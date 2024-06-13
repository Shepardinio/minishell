/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:54:03 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/27 15:03:01 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstmapped;
	t_list	*new;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	lstmapped = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&lstmapped, del);
			free(lstmapped);
			return (NULL);
		}
		ft_lstadd_back(&lstmapped, new);
		lst = lst->next;
	}
	return (lstmapped);
}
