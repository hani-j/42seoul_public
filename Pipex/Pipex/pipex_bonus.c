/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:48:11 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/03 23:32:17 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_next_line.h"

void	fork_process(t_procinfo *p)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		errorprint("pipe error");
	pid = fork();
	printf("fork pid: %d\n", pid);
	if (pid == -1)
		errorprint("fork error");
	else if (pid == 0)
		c_process(fd, p);
	else
		p_process(fd, p);
}

void	process(t_procinfo *p)
{
	if (dup2(p->infile, 0) == -1)
		errorprint("dup failure");
	while (p->start < p->argc - 2)
	{
		fork_process(p);
		waitpid(-1, 0, WNOHANG);
		p->start++;
	}
}

void	multiple(t_procinfo *p)
{
	p->infile = open(p->argv[1], O_RDONLY);
	p->outfile = open(p->argv[p->argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (p->infile == -1 || p->outfile == -1)
		errorprint("open failure");
	p->start = 2;
	process(p);
}

void	heredoc(t_procinfo *p)
{
	char	*line;
	int		len;

	len = ft_strlen(p->argv[2]);
	p->infile = open("tmp", O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (p->infile == -1)
		errorprint("open failure");
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, p->argv[2], len) == 0 && line[len] == '\n')
			break ;
		write(p->infile, line, ft_strlen(line));
	}
	free(line);
	p->infile = open("tmp", O_RDONLY);
	p->outfile = open(p->argv[p->argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	if (p->infile == -1 || p->outfile == -1)
		errorprint("open failure");
	p->start = 3;
	process(p);
}

int	main(int argc, char **argv, char **envp)
{
	t_procinfo	*pinfo;

	pinfo = malloc(sizeof(t_procinfo));
	if (pinfo == 0)
		exit(1);
	pinfo->infile = 0;
	pinfo->outfile = 0;
	pinfo->start = 0;
	pinfo->argc = argc;
	pinfo->argv = argv;
	pinfo->envp = envp;
	if (argc < 5)
		exit(1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
			exit(1);
		heredoc(pinfo);
	}
	else
		multiple(pinfo);
}
