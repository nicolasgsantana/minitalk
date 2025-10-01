/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgsantana <nicolasgsantana@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:40 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/01 17:43:35 by nicolasgsan      ###   ########.fr       */
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
		usleep(BIT_DELAY);
		i++;
	}	
}

void	send_bits(char *message, int pid)
{
	int				i;
	char			mask;
	unsigned char	bit;

	while (*message)
	{
		i = 7;
		while (i >= 0)
		{
			mask = 1 << i;
			bit = (unsigned char)(((unsigned char)*message & mask) >> i);
			if (bit == 0)
				kill(pid, SIGUSR1);
			if (bit == 1)
				kill(pid, SIGUSR2);
			i--;
			usleep(BIT_DELAY);
		}
		message++;
	}
	send_null_byte(pid);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		ft_printf("Server confirmation received.\n");
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		send_bits(message, pid);
	}
	return (0);
}
