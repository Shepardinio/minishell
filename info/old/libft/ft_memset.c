/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:26:17 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/22 11:19:49 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// void *ft_memset(void *s, int c, size_t n)
// {
// 	size_t i;
// 	unsigned char *ptr;

// 	i = 0;
// 	ptr = (unsigned char *)s;
// 	while (i < n)
// 	{
// 		ptr[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (s);
// }
// int	main(void)
// {
// 	char *ptr0 = NULL;
// 	char *ptr1 = NULL;
// 	char buffer1[10];
// 	char buffer2[10];

// 	printf("%p:%p\n", ptr0, buffer1);
// 	ptr0 = memset(buffer1, 'a', 10);
// 	printf("%s:%p\n", buffer1, ptr0);
// 	printf("%p:%p\n", ptr1, buffer2);
// 	ptr1 = ft_memset(buffer2, 'b', 10);
// 	printf("%s:%p\n", buffer2, ptr1);
//     return (0);
// }