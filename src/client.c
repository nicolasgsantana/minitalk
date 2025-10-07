/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:40 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/07 14:56:32 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_client	g_client;

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
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1) // bit received by the server
		(void);
	if (signum == SIGUSR2)
		ft_printf("Server confirmation received.\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	parse_client(argc, argv);
	while (1)
		pause();
	return (0);
}
