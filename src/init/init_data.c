/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:58:40 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/24 18:30:01 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_env(t_data *data, char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	while (env[i] != NULL)
	{
		tmp = ft_split(env[i], '=');
		// printf("%s=%s\n", tmp[0], tmp[1]);
		if (tmp != NULL)
			ft_lstadd_back(&data->env, ft_lstnew(tmp[0], tmp[1]));
		free_tab(tmp);
		i++;
	}

	// while (data->env->next != NULL)
	// {
	// 	ft_putstr_fd(data->env->var, 1);
	// 	write(1, "\n", 1);
	// 	ft_putstr_fd(data->env->value, 1);
	// 	data->env = data->env->next;
	// }
}

void	init_data(t_data *data, char **env)
{
	data->path = ft_split(getenv("PATH"), ':');
	if (env && *env)
		init_env(data, env);
	else
		return; /*create env*/
}
