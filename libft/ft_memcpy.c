/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:31 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/28 14:31:33 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*arr_dest;
	const char	*arr_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	arr_dest = dest;
	arr_src = src;
	i = -1;
	while (++i < n)
		arr_dest[i] = arr_src[i];
	return (dest);
}

// int	main(void)
// {
// 	char src[] = "abcdefghijklmnopqrstuvwxyz";
// 	char dest[30] = {'1', '2', '3'};

// 	printf("%s\n", dest);
// 	ft_memcpy(dest, src, sizeof(char) * 25);
// 	printf("dest: %s\n", dest);

// 	char e[10];
// 	ft_memcpy(e , src + 8, sizeof(char) * 9);
// 	e[9] = '\0';
// 	printf("e: %s\n", e);

// 	char s[] = "Start-stop";
// 	printf("%s\n", s);
// 	ft_memcpy(s + 1 , s + 6, sizeof(char) * 5);
// 	printf("%s\n", s);

// 	char str[] = "foo-bar";
// 	char str1[] = "foo-bar";
// 	ft_memcpy(&str[3], &str[4], 4);
// 	memmove(&str1[3], &str1[4], 4);
// 	printf("%s\n", str);

// 	return (0);
// }