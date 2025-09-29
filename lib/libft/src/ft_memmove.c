/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:58:21 by nde-sant          #+#    #+#             */
/*   Updated: 2025/08/19 09:56:49 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dest;
	s = src;
	i = 0;
	if (d == s)
		return (dest);
	while (i < n && d < s)
	{
		d[i] = s[i];
		i++;
	}
	while (i < n && d > s)
	{
		i++;
		d[n - i] = s[n - i];
	}
	return ((void *)d);
}
