/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:37:43 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/22 11:15:15 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int i;
    char tab[] = "	a bz123ABZ*";

    i = 0;
    while (tab[i])
    {
        printf ("%c = %d : %d\n", tab[i], isprint(tab[i]), ft_isprint(tab[i]));
        i++;
    }
    return (0);
}*/