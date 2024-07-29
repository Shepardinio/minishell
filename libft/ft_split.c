/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:04:12 by mel-yand          #+#    #+#             */
/*   Updated: 2024/07/29 00:06:56 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char *str, char set)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != set)
		++i;
	return (i);
}

static char	*word_dupe(char *str, char set)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_wordlen(str, set);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		free(word);
		return (NULL);
	}
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

static void	fill_words(char **array, char *str, char set)
{
	int	word_index;
	int	i;

	word_index = 0;
	i = 0;
	while (*str != '\0')
	{
		while (*str == set)
			++str;
		if (*str == '\0')
			break ;
		array[word_index] = word_dupe(str, set);
		if (!array[word_index])
		{
			while (i < word_index)
				free(array[i++]);
			free(array);
			return ;
		}
		++word_index;
		while (*str != '\0' && *str != set)
			++str;
	}
	array[word_index] = NULL;
}

static int	count_words(char *str, char set)
{
	int	num_words;

	num_words = 0;
	while (*str != '\0')
	{
		while (*str == set)
			++str;
		if (*str != '\0')
		{
			++num_words;
			while (*str != '\0' && *str != set)
				++str;
		}
	}
	return (num_words);
}

char	**ft_split(char const *str, char set)
{
	int		num_words;
	char	**array;

	if (!str)
		return (NULL);
	num_words = count_words((char *)str, set);
	array = malloc(sizeof(char *) * (num_words + 1));
	if (!array)
		return (NULL);
	fill_words(array, (char *)str, set);
	return (array);
}

// static int	is_charsep(char c, char sep)
// {
// 	if (c == sep)
// 		return (1);
// 	return (0);
// }

// static int	count_word(const char *s, char sep)
// {
// 	int	i;
// 	int	word;
// 	int	count;

// 	i = 0;
// 	word = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		if (!is_charsep(s[i], sep))
// 		{
// 			if (!word)
// 			{
// 				word = 1;
// 				count++;
// 			}
// 		}
// 		else
// 			word = 0;
// 		i++;
// 	}
// 	return (count);
// }

// static size_t	count_next_word(const char *s, int *index, char sep)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[*index] && s[*index] != sep)
// 	{
// 		(*index)++;
// 		i++;
// 	}
// 	while (s[*index] == sep)
// 		(*index)++;
// 	return (i);
// }

// static void	free_alloc(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	while (arr[i])
// 	{
// 		free(arr[i]);
// 		arr[i] = NULL;
// 		i++;
// 	}
// 	free(arr);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		index;
// 	int		index2;
// 	char	**arr;

// 	if (!s)
// 		return (NULL);
// 	arr = ft_calloc(count_word(s, c) + 1, sizeof(char *));
// 	if (arr == NULL)
// 		return (NULL);
// 	arr[count_word(s, c)] = NULL;
// 	i = 0;
// 	index = 0;
// 	index2 = 0;
// 	while (i < count_word(s, c))
// 	{
// 		arr[i] = ft_substr(s, index, count_next_word(s, &index2, c));
// 		index = index2;
// 		if (arr[i++] == NULL)
// 		{
// 			free_alloc(arr);
// 			return (NULL);
// 		}
// 	}
// 	return (arr);
// }

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