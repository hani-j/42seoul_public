/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 07:52:35 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/30 14:48:03 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	// int		fd[2];
	// pid_t	pid;
	// char	str[10];
	// int		status;

	// if (pipe(fd) == -1)
	// 	return (0);
	// printf("fd[0] : %d\n", fd[0]);
	// printf("fd[1] : %d\n", fd[1]);
	// pid = fork();
	// if (pid == -1)
	// 	exit(1);
	// if (pid == 0)
	// {
	// 	printf("\n****자식프로세스****\n");
	// 	printf("변수pid값: %d\n", pid);
	// 	printf("자식피드: %d\n", getpid());
	// 	close(fd[1]);
	// 	dup2(fd[0], 0);
	// 	read(0, str, 1024);
	// 	printf("str : %s\n", str);
	// 	close(fd[0]);

	// 	if (str[0] != 0)
			
	// }
	// else
	// {
	// 	printf("\n****부모프로세스****\n");
	// 	printf("변수pid값: %d\n", pid);
	// 	printf("부모피드: %d\n", getpid());
	// 	close(fd[0]);
	// 	dup2(fd[1], 1);
	// 	write(1, "hello", 5);
	// }
	// return (0);

	int		i;
	int		j;
	char	*path;
	char	*tmp;
	char	**split;

	i = 0;
	while (envp[i])
	{
		printf("envp[%d] : %s\n", i, envp[i]);
		i++;
	}
	i = 0;
	j = 0;
	path = 0;
	split = ft_split(envp[3], ':');
	while (split[i])
	{
		printf("split : %s\n", split[i]);
		tmp = ft_strjoin(split[i], "/");
		printf("tmp : %s\n", tmp);
		path = ft_strjoin(tmp, "ls");
		printf("path : %s\n", path);
		if (access(path, X_OK) == 0)
			printf("성공 str : %s\n", path);
		free(tmp);
		free(path);
		i++;
	}
}
