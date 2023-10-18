/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:32:09 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/03 23:34:02 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmd_path(char *cmd, char **envp)
{
	char	**split;
	char	*cmdpath;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	if (ft_strncmp(envp[i], "PATH", 4) == 0)
	{
		j = 0;
		split = ft_split(envp[i] + 5, ':');
		while (split[j])
		{
			tmp = ft_strjoin(split[j++], "/");
			cmdpath = ft_strjoin(tmp, cmd);
			if (access(cmdpath, X_OK) == 0)
				return (cmdpath);
			free(tmp);
			free(cmdpath);
		}
	}
	errorprint("command not found");
	return (0);
}

char	**cmd_check(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (cmd == 0)
		errorprint("command not found");
	return (cmd);
}

void	c_process(int *fd, t_procinfo *p)
{
	char	*cmdpath;
	char	**cmd;

	cmd = cmd_check(p->argv[p->start]);
	if (access(cmd[0], X_OK) == 0)
		cmdpath = cmd[0];
	else
		cmdpath = cmd_path(cmd[0], p->envp);
	if (close(fd[0]) == -1)
		errorprint("close failure");
	if (dup2(fd[1], 1) == -1)
		errorprint("dup failure");
	if (execve(cmdpath, cmd, p->envp) == -1)
		errorprint("execve failure");
	if (close(fd[1]) == -1)
		errorprint("close failure");
}

void	p_process(int *fd, t_procinfo *p)
{
	char	*cmdpath;
	char	**cmd;

	waitpid(-1, 0, WNOHANG);
	waitpid(-1, 0, WNOHANG);
	cmd = cmd_check(p->argv[p->argc - 2]);
	if (access(cmd[0], X_OK) == 0)
		cmdpath = cmd[0];
	else
		cmdpath = cmd_path(cmd[0], p->envp);
	if (access("tmp", F_OK) == 0)
	{
		if (unlink("tmp") == -1)
			errorprint("unlink failure");
	}
	if (close(fd[1]) == -1)
		errorprint("close failure");
	if (dup2(p->outfile, 1) == -1)
		errorprint("dup failure");
	if (execve(cmdpath, cmd, p->envp) == -1)
		errorprint("execve failure");
}

/*
void	parent_process(int *fd, t_procinfo *p)
{
	char	*cmdpath;
	char	**cmd;

	cmd = cmd_check(argv[3]);
	if (access(cmd[0], X_OK) == 0)
		cmdpath = cmd[0];
	else
		cmdpath = cmd_path(cmd[0], envp);
	if (close(fd[1]) == -1)
		errorprint("close failure");
	if (dup2(fd[0], 0) == -1)
		errorprint("dup failure");
	if (execve(cmdpath, cmd, envp) == -1)
		errorprint("execve failure");
	if (close(fd[0]) == -1)
		errorprint("close failure");
}

void	last_process(t_procinfo *p)
{
	pid_t	pid;
	char	*cmdpath;
	char	**cmd;

	pid = fork();
	cmd = cmd_check(p->argv[p->argc - 2]);
	if (access(cmd[0], X_OK) == 0)
		cmdpath = cmd[0];
	else
		cmdpath = cmd_path(cmd[0], envp);
	if (pid == -1)
		errorprint("fork error");
	else if (pid == 0)
	{
		if (access("tmp_file", F_OK) == 0)
		{
			if (unlink("tmp_file") == -1)
				errorprint("unlink failure");
		}
		if (execve(cmdpath, cmd, envp) == -1)
			errorprint("execve failure");
	}
	else
		wait(0);
}
*/