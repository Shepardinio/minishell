/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:04:10 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/30 13:47:06 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_tab(char **tab)
{
    int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
	tab = NULL;
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

int	count_str(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_list	*find(t_data *data, char *varname)
{
	t_list	*tmp;

	tmp = data->env;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, varname) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
