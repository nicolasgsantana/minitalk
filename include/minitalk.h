/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:34 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/07 14:51:02 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>

# define INPUT_ERR = "Invalid Input.\nUsage:\n\t./client [server_pid] [message]\n"
# define PID_ERR = "Operation not permitted with current PID.\n"

typedef struct	s_client
{
	char	*msg;
	int		server_pid;
}			t_client;

#endif
