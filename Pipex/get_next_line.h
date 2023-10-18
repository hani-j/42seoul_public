/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:05:07 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/02 14:50:55 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1024

char	*get_next_line(int fd);
char	*save_update(char *save);
char	*get_line(char *save);
char	*all_line(int fd, char *save);

size_t	ft_gstrlen(const char *s);
char	*ft_gstrchr(const char *s, int c);
char	*ft_gstrjoin(char *s1, char *s2);

#endif
