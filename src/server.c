/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:59:35 by nde-sant          #+#    #+#             */
/*   Updated: 2025/09/30 12:04:45 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_byte(char bit)
{
	static int	bit_count = 0;
	static char	current_char = 0;

	if (bit_count < 8)
		current_char = (current_char << 1) | bit;
	bit_count++;
	if (bit_count >= 8)
	{
		write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		print_byte(0);
	else if (signum == SIGUSR2)
		print_byte(1);
}

int	main(void)
{
	ft_printf("Server started\n");
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
