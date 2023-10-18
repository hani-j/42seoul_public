/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:05:33 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/02 16:56:28 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_procinfo
{
	int		argc;
	int		infile;
	int		outfile;
	int		start;
	char	**argv;
	char	**envp;
}	t_procinfo;

void			parent_process(int *fd, char **argv, char **envp);
void			child_process(int *fd, char **argv, char **envp);
char			*cmd_path(char *cmd, char **envp);
char			**cmd_check(char *argv);

void			errorprint(const char *str);
int				ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(char *s1, char *s2);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_count(char const *s, char c);
int				ft_splitlen(char const *s, char c);
char			**ft_splitfree(char **split, int index);
char			**ft_split(char const *s, char c);

void			heredoc(t_procinfo *p);
void			multiple(t_procinfo *p);
void			process(t_procinfo *p);
void			fork_process(t_procinfo *p);

void			c_process(int *fd, t_procinfo *p);
void			p_process(int *fd, t_procinfo *p);

#endif