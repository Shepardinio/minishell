/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:08:18 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/28 14:43:17 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}

// int	main(void)
// {
// 	char src[] = "abcdefghijklmnopqrstuvwxyz";
// 	char dest[30] = {'1', '2', '3'};

// 	printf("%s\n", dest);
// 	ft_memmove(dest, src, sizeof(char) * 25);
// 	printf("dest: %s\n", dest);

// 	char e[10];
// 	ft_memmove(e , src + 8, sizeof(char) * 9);
// 	e[9] = '\0';
// 	printf("e: %s\n", e);

// 	char s[] = "Start-stop";
// 	printf("%s\n", s);
// 	ft_memmove(s + 1 , s + 6, sizeof(char) * 5);
// 	printf("%s\n", s);

// 	char str[] = "foo-bar";
// 	char str1[] = "foo-bar";
// 	ft_memmove(&str[3], &str[4], 4);
// 	ft_memmove(&str1[4], &str1[3], 4);
// 	printf("%s\n", str);
// 	printf("%s\n", str1);

// 	return (0);
// }
// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	buffer[n];
// 	size_t			i;

// 	i = 0;
// 	if (dest == NULL && src == NULL)
// 		return (NULL);
// 	while (i < n)
// 	{
// 		buffer[i] = ((const unsigned char *)src)[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		((unsigned char *)dest)[i] = buffer[i];
// 		i++;
// 	}
// 	return (dest);
// }
