/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:00:05 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/22 11:45:52 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char *buffer1 = NULL;
// 	char buffer2[10];

// 	bzero(buffer1, 10);
// 	printf("%s.\n", buffer1);
// 	bzero(buffer2, 10);
// 	printf("%s.\n", buffer2);
//     return (0);
// }