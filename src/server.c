/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:59:35 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/07 18:07:06 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_server;

void	init_server(void)
{
	g_server.client_pid = 0;
	g_server.bit_count = 0;
	g_server.byte = 0;
}

void	write_byte(char bit)
{
	g_server.byte = (g_server.byte << 1) | bit;
	g_server.bit_count++;
	if (g_server.bit_count == 8)
	{
		if (!g_server.byte)
		{
			write(STDOUT_FILENO, "\n", 1);
			kill(g_server.client_pid, SIGUSR2);
			init_server();
			return ;
		}
		else
			write(STDOUT_FILENO, &g_server.byte, 1);
		g_server.bit_count = 0;
		g_server.byte = 0;
	}
	kill(g_server.client_pid, SIGUSR1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_server.client_pid == 0)
		g_server.client_pid = info->si_pid;
	if (signum == SIGUSR1)
		write_byte(0);
	if (signum == SIGUSR2)
		write_byte(1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server started\nPID: %d\n", getpid());
	init_server();
	while (1)
		pause();
	return (0);
}
