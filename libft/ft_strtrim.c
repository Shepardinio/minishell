/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:58:57 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/21 11:02:50 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1)
		return (NULL);
	start = -1;
	end = ft_strlen(s1);
	while (start++ < end && is_charset(s1[start], set))
		;
	while (end-- > start && is_charset(s1[end], set))
		;
	return (ft_substr(s1, start, end - start + 1));
}

// int	main()
// {
// 	const char tab[] = "je suis un poisson  		";
// 	const char set[] = " 	";
// 	char *new = ft_strtrim(tab, set);

// 	printf("new = [%s]\n", new);
// 	return (0);
// }
