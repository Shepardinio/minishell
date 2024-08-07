/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:58:33 by mel-yand          #+#    #+#             */
/*   Updated: 2024/07/04 18:07:44 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_data data;

	init_data(&data, env);
	while (1)
	{
	
		ft_putstr_fd("Minishell> ", 1);
		char *raw_cmd = get_next_line(0);
		*ft_strchr(raw_cmd, '\n') = '\0';

		char **cmd = ft_split(raw_cmd, ' ');

		if (cmd)
		{
			if (ft_strcmp(cmd[0], "cd") == 0)
				ft_cd(&data, cmd);
			if (ft_strcmp(cmd[0], "echo") == 0)
				ft_echo(cmd);
			if (ft_strcmp(cmd[0], "env") == 0)
				ft_env(data.env, cmd);
			if (ft_strcmp(cmd[0], "export") == 0)
				ft_export(&data, cmd);
			if (ft_strcmp(cmd[0], "pwd") == 0)
				ft_pwd();
			if (ft_strcmp(cmd[0], "unset") == 0)
				ft_unset(&data, cmd);
			if (ft_strcmp(cmd[0], "exit") == 0)
			{
				free_tab(cmd);
				break;
			}
		}
		free_tab(cmd);
	}
	free_all(&data);
	return (0);
}