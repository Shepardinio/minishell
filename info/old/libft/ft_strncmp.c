/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:33:22 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/28 15:36:00 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*src1;
	const unsigned char	*src2;

	i = 0;
	src1 = (const unsigned char *) s1;
	src2 = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	while ((i < n - 1 && src1[i] == src2[i]) && (src1[i] && src2[i]))
		i++;
	if (src1[i] && !src2[i] && i < n)
		return (1);
	if (!src1[i] && src2[i] && i < n)
		return (-1);
	return (src1[i] - src2[i]);
}

// int	main(void)
// {
// 	char tab1[] = "je suis un poisson";
// 	char tab2[] = "je suis un poisson";

// 	printf("%d\n", ft_strncmp(tab1, tab2, 0));
// 	printf("%d\n", strncmp(tab1, tab2, 0));
// 	return (0);
// }