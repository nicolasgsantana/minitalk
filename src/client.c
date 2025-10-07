/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:40 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/07 16:32:46 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile t_client	g_client;

void	parse_client(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_putstr_fd(INPUT_ERR, STDERR_FILENO);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 1 || pid == getpid())
	{
		ft_putstr_fd(PID_ERR, STDERR_FILENO);
		exit(1);
	}
	g_client.server_pid = pid;
	g_client.msg =	argv[2];
	g_client.bit_pos = 7;
	g_client.char_pos = 0;
}

void	send_bit(void)
{
	char			mask;
	unsigned char	bit;

	if (g_client.msg[g_client.char_pos])
	{
		mask = 1 << g_client.bit_pos;
		bit = (g_client.msg[g_client.char_pos] & mask) >> g_client.bit_pos;
		if (bit == 0)
			kill(g_client.server_pid, SIGUSR1);
		if (bit == 1)
			kill(g_client.server_pid, SIGUSR2);
		g_client.bit_pos--;
		if (g_client.bit_pos < 0)
		{
			g_client.bit_pos = 7;
			g_client.char_pos++;
		}
	}
	else
		kill(g_client.server_pid, SIGUSR1);
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1) 
		send_bit();// server ready for next bit
	if (signum == SIGUSR2)
	{
		ft_printf("Server confirmation received.\n"); //TODO: BETTER MESSAGE
		exit (0);
	}		
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	parse_client(argc, argv);
	send_bit();
	while (1)
		pause();
	return (0);
}
