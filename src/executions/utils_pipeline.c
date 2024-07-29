/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:15:46 by mel-yand          #+#    #+#             */
/*   Updated: 2024/07/29 02:16:26 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	reset_fd(int *fd_ptr)
{
	close(*fd_ptr);
	*fd_ptr = -1;
}

void	close_pipe(int pipe[2])
{
	if (pipe[READ] != -1)
		reset_fd(&pipe[READ]);
	if (pipe[WRITE] != -1)
		reset_fd(&pipe[WRITE]);
}

void	close_all_pipe(t_all_pipelines *all_pipes)
{
	int	i;

	i = 0;
	while (all_pipes->pipelines[i])
	{
		close_pipe(all_pipes->pipelines[i]->pipefd);
		i++;
	}
}

void	creat_pipe(t_pipeline **node)
{
	int	i;

	i = 0;
	while (node[i])
	{
		if (node[i]->outfiles[0] == NULL && node[i]->outfiles_ext[0] == NULL && node[i + 1])
		{
			if (pipe(node[i]->pipefd) == -1)
			{
				ft_putstr_fd(node[i]->cmd[0], 2);
				ft_putstr_fd(": Error with pipe creation\n", 2); /*maybe modif*/
			}
			printf("pipe creer index %d\n", i);
		}
		else
		{
			node[i]->pipefd[0] = -1;
			node[i]->pipefd[1] = -1;
		}
		i++;
	}
}
