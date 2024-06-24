/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:58:33 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/24 18:22:05 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_data	data;
	int		i = 0;
	
	init_data(&data, env);
	// ft_putstr_fd("/////////////////////////////////////////////////////////////////////\n", 1);
	while (env[i] != NULL)
	// {
	// 	ft_putstr_fd(env[i], 1);
	// 	write(1, "\n", 1);
	// 	i++;
	// }
	// while (data.path[i] != NULL)
	// {
	// 	ft_putstr_fd(data.path[i], 1);
	// 	write(1, "\n", 1);
	// 	i++;
	// }
	return (0);
}