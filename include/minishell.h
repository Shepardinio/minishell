/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:08:29 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/30 18:33:26 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h> 
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "../libft/libft.h"
# include "./struct.h"
# include "./builtins.h"

void	init_data(t_data *data, char **env);

////////// UTILS //////////

void	free_tab(char **tab);
void	free_all(t_data *data);
int		count_str(char **str);
t_list	*find(t_data *data, char *varname);

#endif