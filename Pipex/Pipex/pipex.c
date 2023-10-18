/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:01:00 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/03 16:15:53 by hjeong           ###   ########.fr       */
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

void	child_process(int *fd, char **argv, char **envp)
{
	int		infile;
	char	*cmdpath;
	char	**cmd;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		errorprint(argv[1]);
	cmd = cmd_check(argv[2]);
	if (access(cmd[0], X_OK) == 0)
		cmdpath = cmd[0];
	else
		cmdpath = cmd_path(cmd[0], envp);
	if (close(fd[0]) == -1)
		errorprint("close failure");
	if (dup2(infile, 0) == -1 || dup2(fd[1], 1) == -1)
		errorprint("dup failure");
	if (execve(cmdpath, cmd, envp) == -1)
		errorprint("execve failure");
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int		outfile;
	char	*cmdpath;
	char	**cmd;

	waitpid(-1, 0, WNOHANG);
	outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile == -1)
		errorprint(argv[4]);
	cmd = cmd_check(argv[3]);
	if (access(cmd[0], X_OK) == 0)
		cmdpath = cmd[0];
	else
		cmdpath = cmd_path(cmd[0], envp);
	if (close(fd[1]) == -1)
		errorprint("close failure");
	if (dup2(outfile, 1) == -1 || dup2(fd[0], 0) == -1)
		errorprint("dup failure");
	if (execve(cmdpath, cmd, envp) == -1)
		errorprint("execve failure");
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		errorprint("arg error");
	if (pipe(fd) == -1)
		errorprint("pipe error");
	pid = fork();
	if (pid == -1)
		errorprint("fork error");
	else if (pid == 0)
		child_process(fd, argv, envp);
	else
		parent_process(fd, argv, envp);
}
