/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:15:49 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/28 13:59:44 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	char tab0[] = "Gougougaga";
	char tab1[] = "";
	char tab2[] = "ihazpoudhbsqjbvjqpbfuzpguoahbfupô";
	char *tab3 = NULL;
	
	printf("%ld\n%ld\n", ft_strlen(tab0), strlen(tab0));
	printf("%ld\n%ld\n", ft_strlen(tab1), strlen(tab1));
	printf("%ld\n%ld\n", ft_strlen(tab2), strlen(tab2));
	printf("%ld\n%ld\n", ft_strlen(tab3), strlen(tab3));
	return (0);
}*/