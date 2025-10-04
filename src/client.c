/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:40 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/04 16:19:27 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_null_byte(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		i++;
	}
}

void	send_bits(char *msg, int pid)
{
	static int			bit_count = 7;
	char				mask;
	static const char	*message;
	unsigned char		bit;

	if (msg)
		message = msg;
	if (*message)
	{
		mask = 1 << bit_count;
		bit = (unsigned char)(((unsigned char)*message & mask) >> bit_count);
		if (bit == 0)
			kill(pid, SIGUSR1);
		if (bit == 1)
			kill(pid, SIGUSR2);
		bit_count--;
	}
	else
		send_null_byte(pid);
	if (bit_count < 0)
	{
		bit_count = 7;
		message++;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR2)
		ft_printf("Server confirmation received.\n");
	if (signum == SIGUSR1)
		send_bits(NULL, info->si_pid);
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*message;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		send_bits(message, pid);
		while (1)
			pause();
	}
	return (0);
}
