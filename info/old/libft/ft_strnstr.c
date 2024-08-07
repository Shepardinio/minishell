/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:25:28 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/28 15:04:06 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const char			*s;
	const char			*t;
	char const*const	start = str;

	if (*to_find == '\0')
		return ((char *)str);
	if ((str == NULL || to_find == NULL) && len == 0)
		return (NULL);
	while (*str != '\0' && len > 0)
	{
		s = str;
		t = to_find;
		while (*t != '\0' && *s == *t
			&& (size_t)(s - start) < (str - start + len))
		{
			s++;
			t++;
		}
		if (*t == '\0')
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char tab[] = "aaabcabcd";
// 	const char tab1[] = "cd";
// 	printf("%s\n", ft_strnstr(tab, tab1, strn8));
// 	printf("%s\n", strnstr(tab, tab1, 6));
// 	return (0);
// }