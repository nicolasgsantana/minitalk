/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:34:01 by nicolas           #+#    #+#             */
/*   Updated: 2025/09/15 10:54:19 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ptrtohex(void *ptr)
{
	uintptr_t	n;

	if (!ptr)
		return (NULL);
	n = (uintptr_t)ptr;
	return (ft_itohex(n, 0));
}
