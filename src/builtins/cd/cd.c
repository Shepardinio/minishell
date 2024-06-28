/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:50:30 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/28 21:17:55 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	cd_home()
{
	
}

void	ft_cd(t_data *data, char **arg)
{
	char *path;

	if (count_str(arg) > 2)
	{
		ft_putstr_fd("Minishell: cd: too many arguments\n", 2);
		/*STATUS == 1*/
		return ;
	}
	path = arg[1];
	if (path == NULL)
	{
		cd_home(data);
		/*STATUS == 1*/
		return ;
	}
	else
}
