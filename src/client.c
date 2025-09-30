/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:40 by nde-sant          #+#    #+#             */
/*   Updated: 2025/09/30 17:37:14 by nde-sant         ###   ########.fr       */
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
			bit = (unsigned char)((*message & mask) >> i);
			if (bit == 0)
				kill(pid, SIGUSR1);
			if (bit == 1)
				kill(pid, SIGUSR2);
			i--;
			usleep(50);
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
