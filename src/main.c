/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:58:33 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/30 18:37:44 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_data	data;
	
	init_data(&data, env);
	ft_cd(&data, argv);
	ft_env(data.env, &argv[1]);
	// ft_pwd();

	free_all(&data);
	return (0);
}