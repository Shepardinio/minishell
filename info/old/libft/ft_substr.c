/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:30:26 by mel-yand          #+#    #+#             */
/*   Updated: 2024/04/29 19:14:30 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*arr;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len >= ft_strlen((char *)s))
		arr = ft_calloc(ft_strlen((char *)s) - start + 1, sizeof(char));
	else
		arr = ft_calloc(len + 1, sizeof(char));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		arr[i] = (char)s[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

// int	main(void)
// {
//     const char tab[] = "gougougaga";
//     char *ntab = ft_substr(tab, 0, 0);
//     if (ntab == NULL)
//         return (printf("error alloction"));
//     printf("%s\n", ntab);
//     free(ntab);
//     return 0;
// }