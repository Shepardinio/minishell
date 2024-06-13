/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:24:22 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/28 15:10:04 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	i;

	i = ft_strlen(src);
	while (i != -1)
	{
		if (src[i] == (char)c)
			return ((char *) &src[i]);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char tab[] = "aabcdefgh";
// 	printf("%p\n%p\n%s\n", tab, ft_strrchr(tab, 'e'), ft_strrchr(tab, 'e'));
// 	printf("%p\n%p\n%s\n", tab, strrchr(tab, 'e'), strrchr(tab, 'e'));
// 	return (0);
// }
// if (src == NULL)
// 	return (NULL);