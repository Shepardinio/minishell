/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:04:10 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/26 20:36:12 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_tab(char **tab)
{
    int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_env(t_list **env)
{
	t_list *cur;
	t_list *prev;

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
