/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 06:47:30 by bince             #+#    #+#             */
/*   Updated: 2024/08/13 06:47:31 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_nns(t_nns *nns)
{
	if (nns)
	{
		if (nns->name)
			free(nns->name);
		if (nns->newstr)
			free(nns->newstr);
		free(nns);
	}
}
