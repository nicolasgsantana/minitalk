/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:07:22 by nde-sant          #+#    #+#             */
/*   Updated: 2025/08/19 09:56:28 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		to_find;
	size_t				i;

	src = s;
	to_find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == to_find)
			return ((unsigned char *)&src[i]);
		i++;
	}
	return (NULL);
}
