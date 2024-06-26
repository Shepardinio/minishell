/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:58:40 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/26 23:57:25 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shlvl_up(t_data *data, char *lvl)
{
	char	*lvlup;

	lvlup = ft_itoa(ft_atoi(lvl) + 1);
	ft_lstadd_back(&data->env, ft_lstnew("SHLVL", lvlup));
	free(lvlup);
}

void	init_env(t_data *data, char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	while (env[i] != NULL)
	{
		tmp = ft_split(env[i], '=');
		if (ft_strncmp(tmp[0], "SHLVL", 6) == 0)
			shlvl_up(data, tmp[1]);
		else if (tmp != NULL)
			ft_lstadd_back(&data->env, ft_lstnew(tmp[0], tmp[1]));
		free_tab(tmp);
		i++;
	}
}

void	creat_env(t_data *data)
{
	ft_lstadd_back(&data->env, ft_lstnew("PWD", getcwd(NULL, 0)));
	ft_lstadd_back(&data->env, ft_lstnew("SHLVL", "1"));
	// while (data->env->next != NULL)
	// {
	// 	ft_putstr_fd(data->env->var, 1);
	// 	write(1, "=", 1);
	// 	ft_putstr_fd(data->env->value, 1);
	// 	write(1, "\n", 1);
	// 	data->env = data->env->next;
	// }
}

void	init_data(t_data *data, char **env)
{
	data->env = NULL;
	data->path = ft_split(getenv("PATH"), ':');
	
	if (env && *env)
		init_env(data, env);
	else
		creat_env(data);
}
