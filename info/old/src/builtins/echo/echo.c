/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:07:53 by mel-yand          #+#    #+#             */
/*   Updated: 2024/07/04 17:40:20 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_echo(char **arg)
{
	int	i;
	int n;

	i = 1;
	n = 0;
	if (arg[1] == NULL)
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	while (arg[i] && ft_strncmp(arg[i], "-n", 3) == 0)
	{
		i++;
		n++;
	}
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		if (arg[i] && arg[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (n == 0)
		ft_putchar_fd('\n', 1);
	/*STATUS == 0*/
}
