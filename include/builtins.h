/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:03:41 by mel-yand          #+#    #+#             */
/*   Updated: 2024/07/03 17:12:49 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTINS_H
# define BULTINS_H

void	ft_cd(t_data *data, char **arg);
void	ft_echo(char **arg);
void	ft_env(t_list *env, char **cmd);
void	ft_pwd(void);
void	ft_unset(t_data *data, char **arg);

#endif