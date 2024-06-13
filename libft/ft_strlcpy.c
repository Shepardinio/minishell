/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:40:52 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/28 15:08:43 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// int	main()
// {
// 	const char src[] = "le j c'est le h";
// 	char *dest = NULL;
// 	int i = ft_strlcpy(dest, src, sizeof(dest));

// 	printf("dest[%s] taille dest[%d]", dest, i);
// 	return (0);
// }
	// if (!dst || !src)
	// 	return (0);