/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:03:41 by mel-yand          #+#    #+#             */
/*   Updated: 2024/06/30 14:32:08 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTINS_H
# define BULTINS_H

void	ft_pwd(void);
void	ft_env(t_list *env, char **cmd);
void	ft_cd(t_data *data, char **arg);

#endif