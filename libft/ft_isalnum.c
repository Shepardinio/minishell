/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:41:59 by mel-yand          #+#    #+#             */
/*   Updated: 2023/11/22 11:14:43 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
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
        printf ("%c = %d : %d\n", tab[i], isalnum(tab[i]), ft_isalnum(tab[i]));
        i++;
    }
    return (0);
}*/