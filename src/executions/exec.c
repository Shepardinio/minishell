/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:08:42 by mel-yand          #+#    #+#             */
/*   Updated: 2024/07/22 03:55:44 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_cmd(t_data *data)
{
	int				i;
	t_all_pipelines	*tmp;

	i = 0;
	if (data == NULL || data->all_pipes == NULL)
		return (0);
	tmp = data->all_pipes;
	while (tmp->pipelines[i])
		i++;
	return (i);
}

void	wait_child(t_data *data, pid_t exit_status, int nb_process)
{
	int		status;
	pid_t	child_pid;
	
	while (nb_process)
	{
		child_pid = waitpid(exit_status, &status, 0);
		if (child_pid == exit_status)
		{
			if (WIFEXITED(status))
				data->status = WEXITSTATUS(status);
		}
		nb_process--;
	}
}

int	is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (0);
	else if (!ft_strncmp(cmd, "cd", 3) 
			|| !ft_strncmp(cmd, "echo", 5)
			|| !ft_strncmp(cmd, "env", 4)
			|| !ft_strncmp(cmd, "export", 7)
			|| !ft_strncmp(cmd, "pwd", 4)
			|| !ft_strncmp(cmd, "unset", 6))
		return (1);
	return (0);
}

int	exec_builtins(t_data *data, t_pipeline *node)
{
	if (is_builtin(node->cmd[0]) == 0)
		return (0);
	if (ft_strncmp(node->cmd[0], "cd", 3) == 0)
		ft_cd(data, node->cmd);
	else if (ft_strncmp(node->cmd[0], "echo", 5) == 0)
		ft_echo(node->cmd);
	else if (ft_strncmp(node->cmd[0], "env", 4) == 0)
		ft_env(data->env, node->cmd);
	else if (ft_strncmp(node->cmd[0], "export", 7) == 0)
		ft_export(data, node->cmd);
	else if (ft_strncmp(node->cmd[0], "pwd", 4) == 0)
		ft_pwd();
	else if (ft_strncmp(node->cmd[0], "unset", 6) == 0)
		ft_unset(data, node->cmd);
	return (1);
}

void	exec_cmd(t_data *data, char **arg)
{
	char	*cmd;

	cmd = get_env_path(data, arg); /*FAIRE*/
	if (cmd != NULL && access(cmd, X_OK) == 0)
		execve(cmd, arg, envp);
	if (cmd != NULL && access(cmd, F_OK) == 0)
	{
		ft_putstr_fd("MiniShell: ", 2);
		ft_putstr_fd(arg[0], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		free(cmd);
		// free_exit(data, 126);
	}
	ft_putstr_fd("MiniShell: ", 2);
	ft_putstr_fd(arg[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free(cmd);
	// free_exit(data, 127);
}

void	child(t_data *data, t_pipeline *node)
{
	/*FONCTION: CLOSE NO USED*/
	/*DUP*/
	if (exec_builtins(data, node) == 1)
		free_exit(data, EXIT_SUCCESS);
	exec_cmd(data, node->cmd);
}

pid_t	start_exec(t_data *data, t_pipeline **node, int index)
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
		child(data, node[index]);
	}
	/*CLOSE NO USED*/
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
		tmp[i]->pid = start_exec(data, tmp, i);
		exit_status = tmp[i]->pid;
		i++;
	}
	return (exit_status);
}

void	execution(t_data *data)
{
	int	nb_process;
	int	exit_status;

	nb_process = count_cmd(data);
	/*creat pipe*/
	printf("nb cmd %d\n", nb_process);
	exit_status = launch_cmd(data, nb_process);
	if (exit_status != -1)
		wait_child(data, exit_status, nb_process);
}