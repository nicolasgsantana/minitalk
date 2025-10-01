/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:10:39 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/01 14:37:07 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int last_client_pid;

void	print_byte(char bit, siginfo_t *info)
{
	static int	bit_count = 0;
	static char	current_char = 0;

	if (bit_count < 8)
		current_char = (current_char << 1) | bit;
	bit_count++;
	if (bit_count >= 8)
	{
		if (!current_char)
		{
			kill(info->si_pid, SIGUSR1);
			current_char = '\n';
		}
		write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		print_byte(0, info);
	else if (signum == SIGUSR2)
		print_byte(1, info);
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
	while (1)
	{
		pause();
	}
	return (0);
}
