/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:10:49 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/01 16:24:32 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	if (src == NULL)
		return (NULL);
	while (*src)
	{
		if (*src == (char)c)
			return ((char *)src);
		src++;
	}
	return (NULL);
}

// char	*ft_strchr(const char *src, int c)
// {
// 	while (*src)
// 	{
// 		if ((char)*src == (char)c)
// 			return ((char *)src);
// 		src++;
// 	}
// 	if ((char)*src == (char)c)
// 		return ((char *)src);
// 	return (NULL);
// }