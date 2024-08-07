/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:26:42 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/22 11:15:03 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int i;
    char tab[] = "abz01239ABZ*";

    i = 0;
    while (tab[i])
    {
        printf ("%c = %d : %d\n", tab[i], isdigit(tab[i]), ft_isdigit(tab[i]));
        i++;
    }
    return (0);
}*/