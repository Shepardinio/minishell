/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:15:46 by mel-yand          #+#    #+#             */
/*   Updated: 2024/07/25 15:29:56 by mel-yand         ###   ########.fr       */
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
		close_pipe(&all_pipes->pipelines[i]->pipefd[READ]);
		close_pipe(&all_pipes->pipelines[i]->pipefd[WRITE]);
		i++;
	}
}