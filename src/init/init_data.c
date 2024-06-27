/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:58:40 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/27 23:49:45 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	shlvl_up(t_data *data, char *lvl)
{
	char	*lvlup;

	lvlup = ft_itoa(ft_atoi(lvl) + 1);
	ft_lstadd_back(&data->env, ft_lstnew("SHLVL", lvlup));
	free(lvlup);
}

static void	check_pwd_shlvl(t_data *data, int *pwd, int *shlvl)
{
	printf("pwd = %d shlvl = %d\n", *pwd, *shlvl);
	if (pwd == 0)
		ft_lstadd_back(&data->env, ft_lstnew("PWD", getcwd(NULL, 0)));
	if (shlvl == 0)
	{
		ft_lstadd_back(&data->env, ft_lstnew("SHLVL", "1"));
		printf("SKDJSKFKSF\n");
	}
}

static void	init_env(t_data *data, char **env)
{
	int		i;
	char	**tmp;
	int		pwd;
	int		shlvl;

	i = 0;
	pwd = 0;
	shlvl = 0;
	printf("------------------------->%s\n", env[i]);
	printf("------------------------->%s\n", env[1]);
	printf("------------------------->%s\n", env[2]);
	while (env[i] != NULL)
	{
		tmp = ft_split(env[i], '=');
		if(ft_strncmp(tmp[0], "PWD", 4) == 0)
		{
			printf("%s\n", tmp[0]);
			pwd = 1;
		}
		if (ft_strncmp(tmp[0], "SHLVL", 6) == 0)
		{
			shlvl_up(data, tmp[1]);
			shlvl = 1;
		}
		else if (tmp != NULL)
			ft_lstadd_back(&data->env, ft_lstnew(tmp[0], tmp[1]));
		free_tab(tmp);
		i++;
	}
	check_pwd_shlvl(data, &pwd, &shlvl);
}

void	init_data(t_data *data, char **env)
{
	data->env = NULL;
	data->path = ft_split(getenv("PATH"), ':');
	
	if (env && *env)
		init_env(data, env);
	else
	{
		ft_lstadd_back(&data->env, ft_lstnew("PWD", getcwd(NULL, 0)));
		ft_lstadd_back(&data->env, ft_lstnew("SHLVL", "1"));
	}
}
