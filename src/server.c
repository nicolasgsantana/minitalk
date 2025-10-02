/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:59:35 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/02 13:18:21 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	concat_message(char new_char)
{
	static char	*message = "";
	char		*temp;
	int			i;

	if (!new_char && message[0])
	{
		ft_printf("%s", message);
		free(message);
		message = "";
		return ;
	}
	temp = message;
	message = ft_calloc(sizeof(char), ft_strlen(message) + 2);
	i = 0;
	while (temp[i])
	{
		message[i] = temp[i];
		i++;
	}
	if (temp[0])
		free(temp);
	message[i] = new_char;
}

void	get_byte(char bit, siginfo_t *info)
{
	static int	bit_count = 0;
	static char	current_char = 0;

	if (bit_count < 8)
		current_char = (current_char << 1) | bit;
	bit_count++;
	if (bit_count >= 8)
	{
		if (!current_char)
			kill(info->si_pid, SIGUSR1);
		concat_message(current_char);
		bit_count = 0;
		current_char = 0;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		get_byte(0, info);
	else if (signum == SIGUSR2)
		get_byte(1, info);
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
