/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:13:14 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/24 16:01:20 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *var, char *value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->var = NULL;
	new->value = NULL;
	if (var)
		new->var = ft_strdup(var);
	if (value)
		new->value = ft_strdup(value);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
