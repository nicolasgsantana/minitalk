/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:46:52 by nde-sant          #+#    #+#             */
/*   Updated: 2025/08/19 09:56:12 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*last_node;

	new_list = ft_lstnew(f(lst -> content));
	if (!new_list)
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	lst = lst -> next;
	while (lst)
	{
		ft_lstadd_back(&new_list, ft_lstnew(f(lst -> content)));
		last_node = ft_lstlast(new_list);
		if (!last_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst -> next;
	}
	return (new_list);
}
