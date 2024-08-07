/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:06:01 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/28 15:40:20 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	i = 0;
	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((i < n - 1 && ptr1[i] == ptr2[i]))
		i++;
	return (ptr1[i] - ptr2[i]);
}

// int	main(void)
// {
// 	const char tab[] = "je suis un poisson";
// 	const char tab1[] = "je suis un poisson";
// 	printf("%d\n", ft_memcmp(tab, tab1, 25));
// 	printf("%d\n", memcmp(tab, tab1, 25));
// 	return (0);
// }