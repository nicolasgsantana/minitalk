/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:34 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/08 10:31:52 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>

# define INPUT_ERR "Invalid Input.\nUsage:\n\t./client [server_pid] [message]\n"
# define PID_ERR "Operation not allowed with current PID.\n"
# define SERVER_CONFIRM "Server confirmation received.\n"

typedef struct	s_client
{
	unsigned char	*msg;
	int				server_pid;
	int				bit_pos;
	int				char_pos;
}					t_client;

typedef struct	s_server
{
	int		client_pid;
	int		bit_count;
	char	byte;
}			t_server;

#endif
