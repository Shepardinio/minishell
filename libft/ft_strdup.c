/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:27:55 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/22 11:20:56 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;

	arr = malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

// int	main(void)
// {
//     const char tab[] = "gougou";
//     char *arr = ft_strdup(tab);
//     if (arr == NULL)
//         return (1);
//     printf("%s\n", arr);
//     free(arr);
//     return 0;
// }