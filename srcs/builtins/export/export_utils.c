/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:21:46 by mel-yand          #+#    #+#             */
/*   Updated: 2024/09/27 01:13:57 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	print_error_export(t_data *data, char *varname)
{
	if (varname[0] == '-')
	{
		ft_putstr_fd("Minishell: export: -", 2);
		ft_putchar_fd(varname[1], 2);
		ft_putstr_fd(": invalid option\n", 2);
		data->status = 2;
	}
	else
	{
		ft_putstr_fd("Minishell: export: ", 2);
		ft_putstr_fd(varname, 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
		data->status = 1;
	}
	return (0);
}

int	valid_name(t_data *data, char *arg)
{
	int	i;

	if (arg[0] == '_' && (arg[1] == '\0' || arg[1] == '='))
		return (0);
	if (arg[0] != '_' && !ft_isalpha(arg[0]))
		return (print_error_export(data, arg));
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (arg[i] != '_' && !ft_isalnum(arg[i]))
			return (print_error_export(data, arg));
		i++;
	}
	return (1);
}

// mel_yand changed here

void	print_variable(t_list *node)
{
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(node->var, 1);
	if (node->value)
	{
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(node->value, 1);
		ft_putstr_fd("\"", 1);
	}
	ft_putstr_fd("\n", 1);
}

int	compare_vars(t_list *a, t_list *b)
{
	int	i;

	i = 0;
	while (a->var[i] && b->var[i] && a->var[i] == b->var[i])
		i++;
	return (a->var[i] - b->var[i]);
}

t_list	*find_min(t_list *env, t_list *last_min)
{
	t_list	*min;
	t_list	*current;

	min = NULL;
	current = env;
	while (current)
	{
		if ((!min || compare_vars(current, min) < 0) && (!last_min || compare_vars(current, last_min) > 0))
			min = current;
		current = current->next;
	}
	return (min);
}

void	export_no_args(t_list *env)
{
	t_list	*min;
	t_list	*current;

	if (!env)
		return ;
	current = NULL;
	while ((min = find_min(env, current)))
	{
		print_variable(min);
		current = min;
	}
}
