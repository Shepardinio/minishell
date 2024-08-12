/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:03:41 by mel-yand          #+#    #+#             */
/*   Updated: 2024/08/12 22:44:50 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTINS_H
# define BULTINS_H

void		ft_cd(t_data *data, char **arg);
void		ft_echo(char **arg);
void		ft_env(t_list *env, char **cmd);
long long	ft_atoll(const char *str);
int			only_digit(char *arg);
int			is_too_big(char *cmd);
void		free_exit(t_data *data, int err);
void		ft_exit(t_data *data, char **arg);
void		ft_export(t_data *data, char **arg);
int			valid_name(t_data *data, char *arg);
void		ft_pwd(void);
void		ft_unset(t_data *data, char **arg);

#endif