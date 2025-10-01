/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:10:37 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/01 12:39:52 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		send_bits(message, pid);
	}
	return (0);
}