/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:54:42 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/22 11:14:14 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int i;
    char tab[] = "abz123ABZ*";

    i = 0;
    while (tab[i])
    {
        printf ("%c = %d : %d\n", tab[i], isalpha(tab[i]), ft_isalpha(tab[i]));
        i++;
    }
    return (0);
}*/