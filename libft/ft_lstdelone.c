/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:04:32 by mel-yand          #+#    #+#             */
/*   Updated: 2024/07/01 01:24:14 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	prev = lst->prev;
	next = lst->next;
	if (lst->var)
		del(lst->var);
	if (lst->value)
		del(lst->value);
	free(lst);
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
}
