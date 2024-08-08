/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:15:46 by mel-yand          #+#    #+#             */
/*   Updated: 2024/08/08 16:06:45 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		// close_pipe(all_pipes->pipelines[i]->pipehd);
		if (all_pipes->pipelines[i]->infile_fd != -1 && all_pipes->pipelines[i]->infile_fd != 0)
			reset_fd(&all_pipes->pipelines[i]->infile_fd);
		if (all_pipes->pipelines[i]->outfile_fd != -1 && all_pipes->pipelines[i]->outfile_fd != 1)
			reset_fd(&all_pipes->pipelines[i]->outfile_fd);
		i++;
	}
}

// void	creat_pipe_heredoc(t_pipeline *node, int i)
// {
// 	if (node->here_docs[0] != NULL)
// 	{
// 		if (pipe(node->pipehd) == -1)
// 			perror("Minishell: Pipe Error");
// 		printf("pipe here doc creer index %d\n", i);
// 		printf("pipehd0=%d, pipehd1=%d\n", node->pipehd[0], node->pipehd[1]);
// 	}
// 	else
// 	{
// 		node->pipehd[0] = -1;
// 		node->pipehd[1] = -1;
// 	}
// }

void	creat_pipe(t_pipeline **node)
{
	int	i;

	i = 0;
	while (node[i])
	{
		if (node[i]->outfiles[0] == NULL && node[i]->outfiles_ext[0] == NULL && node[i + 1]/*|| node[i]->here_docs[0] != NULL*/)
		{
			if (pipe(node[i]->pipefd) == -1)
				perror("Minishell: Pipe Error");
			printf("pipe creer index %d\n", i);
			printf("pipe0=%d, pipe1=%d\n", node[i]->pipefd[0], node[i]->pipefd[1]);
		}
		else
		{
			node[i]->pipefd[0] = -1;
			node[i]->pipefd[1] = -1;
		}
		// creat_pipe_heredoc(node[i], i);
		i++;
	}
}

void	std_handler(t_pipeline **node, int nb_process)
{
	int	i;

	i = 0;
	// if (node[i] && (node[i]->pipefd[0] != -1 && node[i]->pipefd[1] != -1))
	// 	node[i]->outfile_fd = node[i]->pipefd[WRITE];
	// i++;
	while (node[i])
	{
		if (i != 0 && node[i - 1]->pipefd[0] != -1)
			node[i]->infile_fd = node[i - 1]->pipefd[READ];
		if(i != nb_process - 1)
		{
			if (node[i]->pipefd[0] != -1 && node[i]->pipefd[1] != -1)
				node[i]->outfile_fd = node[i]->pipefd[WRITE];
		}
		i++;
	}
}
