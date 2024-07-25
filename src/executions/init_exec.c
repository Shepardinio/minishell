/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:08:42 by mel-yand          #+#    #+#             */
/*   Updated: 2024/07/25 17:07:04 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	wait_child(t_data *data, pid_t exit_status, int nb_process)
{
	int		status;
	pid_t	child_pid;
	int		i;
	
	i = 0;
	while (i < nb_process)
	{
		child_pid = waitpid(data->all_pipes->pipelines[i]->pid, &status, 0);
		if (child_pid == exit_status)
		{
			if (WIFEXITED(status))
				data->status = WEXITSTATUS(status);
		}
		i++;
	}
}

void	exec_cmd(t_data *data, char **arg)
{
	char	*cmd;

	cmd = get_cmd_path(data, arg);
	// if (cmd != NULL && access(cmd, X_OK) == 0)
	// 	execve(cmd, arg, data->env_array);
	// if (cmd != NULL && access(cmd, F_OK) == 0)
	// {
	// 	ft_putstr_fd("MiniShell: ", 2);
	// 	ft_putstr_fd(arg[0], 2);
	// 	ft_putstr_fd(": Permission denied\n", 2);
	// 	free(cmd);
	// 	// free_exit(data, 126);
	// }
	// ft_putstr_fd("MiniShell: ", 2);
	// ft_putstr_fd(arg[0], 2);
	// ft_putstr_fd(": command not found\n", 2);
	free(cmd);
	// // free_exit(data, 127);
}

void	child(t_data *data)
{
	/*DUP*/
	close_all_pipe(data->all_pipes);
	if (exec_builtins(data, data->all_pipes->pipelines[data->index]) == 1)
		return ;
		// free_exit(data, EXIT_SUCCESS);
	exec_cmd(data, data->all_pipes->pipelines[data->index]->cmd);
}

pid_t	start_exec(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("MiniShell: Error");
		return (-1);
	}
	else if (pid == 0)
	{
		child(data);
	}
	return (pid);
}

int	launch_cmd(t_data *data, int nb_process)
{
	t_pipeline	**tmp;
	pid_t		exit_status;
	int			i;

	tmp = data->all_pipes->pipelines;
	exit_status = 0;
	i = 0;
	while (tmp[i] && exit_status != -1 && i < nb_process)
	{
		data->index = i;
		tmp[i]->pid = start_exec(data);
		exit_status = tmp[i]->pid;
		i++;
	}
	return (exit_status);
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

void	execution(t_data *data)
{
	int	nb_process;
	int	exit_status;

	nb_process = count_cmd(data);
	creat_env_char(data);
	creat_pipe(data->all_pipes->pipelines);
	exit_status = launch_cmd(data, nb_process);
	close_all_pipe(data->all_pipes);
	if (exit_status != -1)
		wait_child(data, exit_status, nb_process);
	free_tab(data->env_array);
}





















// void	close_unused_inchild(t_data *data)
// {
// 	int			i;
// 	t_pipeline	**tmp;

// 	i = 0;
// 	tmp = data->all_pipes->pipelines;
// 	while (tmp[i])
// 	{
// 		if ((i + 1) == data->index)
// 			i++;
// 		else
// 		{
// 			if (tmp[i]->pipefd[0] != -1 && tmp[i]->pipefd[1] != -1)
// 			{
// 				close_pipe(tmp[i]->pipefd);
// 				printf("close Pipe[%d]\n", i);
// 			}
// 		}
// 		i++;
// 	}
// }