/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:27:06 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/28 15:07:36 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	copy_len;
	size_t	i;

	if ((dest == NULL || src == NULL) && size == 0)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	copy_len = 0;
	if (size <= dest_len)
		return (size + src_len);
	copy_len = size - dest_len - 1;
	if (copy_len > 0)
	{
		i = 0;
		while (src[i] && i < copy_len)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = '\0';
	}
	return (dest_len + src_len);
}

// int	main(void)
// {
//     char destination[20] = "Hello, ";
//     const char* source = "world!";

//     // Appeler ft_strlcat pour concaténer les chaînes
//     size_t result = ft_strlcat(destination, source, sizeof(destination));

//     // Afficher le résultat
//     printf("Chaîne résultante : %s\n", destination);
//     printf("Longueur totale : %zu\n", result);

//     return 0;
// }
// size_t	ft_strlcat(char *dest, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	len_d;
// 	size_t	len_s;

// 	i = ft_strlen(dest);
// 	len_d = ft_strlen(dest);
// 	len_s = ft_strlen((char *)src);
// 	j = 0;
// 	if (size < 1)
// 		return (len_s + size);
// 	while (i < size - 1 && src[j])
// 	{
// 		dest[i] = src[j];
// 		i++;
// 		j++;
// 	}
// 	dest[i] = '\0';
// 	if (size < len_d)
// 		return (len_s + size);
// 	else
// 		return (len_d + len_s);
// }