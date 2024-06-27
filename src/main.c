/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:58:33 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/27 23:24:22 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_data	data;
	// int		i = 0;
	
	// while (env[i] != NULL)
	// {
	// 	ft_putstr_fd(env[i], 1);
	// 	write(1, "\n", 1);
	// 	i++;
	// }
	// ft_putstr_fd("/////////////////////////////////////////////////////////////////////\n", 1);
	init_data(&data, env);
	ft_env(data.env, &argv[1]);

	// while (data.env)
	// {
	// 	printf("%s=%s\n", data.env->var, data.env->value);
	// 	data.env = data.env->next;
	// }
	// while (data.env->prev != NULL)
	// 	data.env = data.env->prev;
	free_all(&data);
	return (0);
}