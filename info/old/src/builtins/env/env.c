/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:39:00 by mel-yand          #+#    #+#             */
/*   Updated: 2024/07/09 16:24:46 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_env(t_list *env, char **cmd)
{
	if (cmd != NULL && cmd[1] != NULL)
	{
		ft_putstr_fd("env does not take arguments\n", 2);
		/*Change status to 127*/
		return ;
	}
	while (env)
	{
		if (env->value != NULL)
		{
			ft_putstr_fd(env->var, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(env->value, 1);
			ft_putstr_fd("\n", 1);
		}
		env = env->next;
	}
}
