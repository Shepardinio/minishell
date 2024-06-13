/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:04:12 by mel-yand          #+#    #+#             */
/*   Updated: 2024/05/20 17:19:50 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charsep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	count_word(const char *s, char sep)
{
	int	i;
	int	word;
	int	count;

	i = 0;
	word = 0;
	count = 0;
	while (s[i])
	{
		if (!is_charsep(s[i], sep))
		{
			if (!word)
			{
				word = 1;
				count++;
			}
		}
		else
			word = 0;
		i++;
	}
	return (count);
}

static size_t	count_next_word(const char *s, int *index, char sep)
{
	size_t	i;

	i = 0;
	while (s[*index] && s[*index] != sep)
	{
		(*index)++;
		i++;
	}
	while (s[*index] == sep)
		(*index)++;
	return (i);
}

static void	free_alloc(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		index;
	int		index2;
	char	**arr;

	if (!s)
		return (NULL);
	arr = ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr[count_word(s, c)] = NULL;
	i = 0;
	index = 0;
	index2 = 0;
	while (i < count_word(s, c))
	{
		arr[i] = ft_substr(s, index, count_next_word(s, &index2, c));
		index = index2;
		if (arr[i++] == NULL)
		{
			free_alloc(arr);
			return (NULL);
		}
	}
	return (arr);
}

// int	main(int argc, char **argv)
// {
// 	int i;
// 	char **arr;

// 	if (argc < 2)
// 		return (printf("tab vide"));
// 	printf("%s\n", argv[1]);
// 	arr = ft_split(argv[1], ' ');
// 	if (arr == NULL)
// 		return (printf("error"));
// 	i = 0;
// 	while (arr[i])
// 	{
// 		printf("arr[%d] : %s\n", i, arr[i]);
// 		i++;
// 	}
// 	while (arr[i])
// 		free(arr[i++]);
// 	free(arr);
// 	return (0);
// }