/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:10:25 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/28 15:10:25 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*ptrs;
	unsigned char	car;
	size_t			i;

	i = 0;
	ptrs = (unsigned char *) src;
	car = (unsigned char) c;
	while (i < n)
	{
		if (ptrs[i] == car)
			return (ptrs + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char tab[] = "aabcdefgh";
// 	printf("%p\n%p\n", tab, ft_memchr(tab, 'z', 50));
// 	printf("%p\n%p\n", tab, memchr(tab, 'z', 50));
// 	return (0);
// }
// if (src == NULL || n == 0)
// 	return (NULL);