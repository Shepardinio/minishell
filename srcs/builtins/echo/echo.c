/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:07:53 by mel-yand          #+#    #+#             */
/*   Updated: 2024/09/26 20:25:09 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// bince changed here

int	get_outfile(t_data *data)
{
	return (data->all_pipes->pipelines[data->index]->outfile_fd);
}

void	check_echo_arg(char **arg, int *i, int *n)
{
	int	j;

	j = 0;
	while (arg[*i] && (arg[*i][j] == '-' && arg[*i][j + 1] == 'n'))
	{
		if (arg[*i][0] == '-')
			j++;
		while (arg[*i][j] && (arg[*i][j] == 'n' || arg[*i][j] == 'e'))
			j++;
		if (arg[*i][j] != '\0' && (arg[*i][j] != 'n' && arg[*i][j] != 'e'))
			break ;
		*n = 1;
		*i += 1;
	}
}

void	ft_echo(t_data *data, char **arg)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (arg[1] == NULL)
	{
		ft_putchar_fd('\n', get_outfile(data));
		return ;
	}
	check_echo_arg(arg, &i, &n);
	// ft_putnbr_fd(n, 1);
	// ft_putstr_fd(arg[0], 1);
	// ft_putstr_fd("\n--\n", 1);
	// ft_putstr_fd(arg[1], 1);
	// ft_putstr_fd("\n--\n", 1);
	// ft_putstr_fd(arg[2], 1);
	// ft_putstr_fd("\n--\n", 1);
	// ft_putstr_fd(arg[3], 1);
	// ft_putstr_fd("\n--\n", 1);
	// while (arg[i] && ft_strncmp(arg[i], "-n", 2) == 0)
	// {
	// 	i++;
	// 	n++;
	// }
	while (arg[i])
	{
		ft_putstr_fd(arg[i], get_outfile(data));
		if (arg[i] && arg[i + 1])
			ft_putchar_fd(' ', get_outfile(data));
		i++;
	}
	if (n == 0)
		ft_putchar_fd('\n', get_outfile(data));
	data->status = 0;
}
