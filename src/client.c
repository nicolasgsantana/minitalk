/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:40 by nde-sant          #+#    #+#             */
/*   Updated: 2025/09/29 13:19:39 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		ft_printf("Message '%s' sent to pid %d\n", message, pid);
		if (message[0] == '1')
			kill(pid, SIGUSR1);
		else if (message[0] == '2')
			kill(pid, SIGUSR2);
	}
	return (0);
}
