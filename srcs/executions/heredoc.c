/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 02:17:51 by mel-yand          #+#    #+#             */
/*   Updated: 2024/08/07 02:55:41 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	heredoc_redir()
{
	
}

void	heredoc(t_data *data, t_pipeline *node)
{
	pid_t	pid;

	if (!node || node->here_docs[0] == NULL)
		return (perror("Minishell: Error Heredoc"));
	if (node->pipefd[0] == -1 || node->pipefd[1] == -1)
		return (perror("Minishell: Pipe Error"));
	heredoc_redir();
	pid = fork();
	if (pid < 0)
		return (perror("MiniShell: Error"));
	else if (pid == 0)
		child_heredoc();
	waitpid(pid, NULL, 0);
}


