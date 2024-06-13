/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:54:35 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/05 20:24:42 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	value;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	n = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	value = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		value = value * 10 + (str[i] - 48);
		i++;
	}
	return (value * n);
}

// int	ps_atoi(const char *str, int *error)
// {
// 	int	n;
// 	int	value;

// 	while ((*str >= 9 && *str <= 13) || *str == 32)
// 		++str;
// 	n = 1;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			n = -n;
// 		++str;
// 	}
// 	value = 0;
// 	while (*str && (*str >= '0' && *str <= '9'))
// 	{
// 		if ((value >= __INT_MAX__ / 10)
// 			&& (((n == 1 && (*str - 48) > 7)
// 					|| (n == -1 && (*str - 48) > 8))))
// 			return (*error = 1, 0);
// 		value = value * 10 + (*str - 48);
// 		++str;
// 	}
// 	return (*error = 0, value * n);
// }