/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:24:47 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/27 15:50:00 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb * size == 0)
		return (malloc(0));
	if (nmemb > ((size_t)-1) / size - 1)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// int	main(void)
// {
//     int i = 0;
//     int b = 15;

//     int *p;
//     p = ft_calloc(10, 0);
//     if (p == NULL)
//         return (1);
//     while (i < b)
//     {
//         printf("%d", p[i]);
//         i++;
//     }
//     i = 0;
//     printf(" : ");
//     free(p);
//     return 0;
// }