/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:04:10 by mel-yand          #+#    #+#             */
/*   Updated: 2024/08/13 13:17:03 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_env(t_list **env)
{
	t_list	*cur;
	t_list	*prev;

	cur = *env;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev->var);
		free(prev->value);
		free(prev);
	}
}

void	free_all(t_data *data)
{
	free_tab(data->path);
	free_env(&data->env);
}
