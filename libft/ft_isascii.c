/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:21:18 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/22 11:14:53 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int i;
    char tab[] = " abz123ABZ*";

    i = 0;
    while (tab[i])
    {
        printf ("%c = %d : %d\n", tab[i], isascii(tab[i]), ft_isascii(tab[i]));
        i++;
    }
    return (0);
}*/