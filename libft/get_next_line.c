/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:44:52 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/29 15:57:01 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*readfile(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes;

	bytes = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (bytes > 0 && ft_strchr(*stash, '\n') == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), NULL);
		buffer[bytes] = '\0';
		if (bytes > 0)
		{
			*stash = ft_strjoin(*stash, buffer);
		}
	}
	return (free(buffer), *stash);
}

static char	*get_line(char *s)
{
	char	*temp;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		return (NULL);
	temp[i] = '\0';
	i--;
	while (i >= 0)
	{
		temp[i] = s[i];
		i--;
	}
	return (temp);
}

static char	*get_next(char *s)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	temp = malloc(ft_strlen((s + i)) + 1 * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		temp[j++] = s[i++];
	temp[j] = '\0';
	free(s);
	if (j == 0)
		return (free(temp), NULL);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), NULL);
	readfile(fd, &stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = get_next(stash);
	return (line);
}

// int main(void)
// {
// 	int		fd = open("texte.txt", O_RDONLY);
// 	char	*temp = get_next_line(fd);

// 	while (temp != NULL)
// 	{
// 		printf("line: %s\n", temp);
// 		free(temp);
// 		temp = get_next_line(fd);
// 	}
// 	free(temp);
// 	close(fd);
// 	return(0);
// }