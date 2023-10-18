/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:56:53 by hjeong            #+#    #+#             */
/*   Updated: 2022/04/13 20:39:07 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*all_line(int fd, char *save)
{
	char	*buffer;
	int		byte;

	byte = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (!ft_strchr(save, '\n') && byte == BUFFER_SIZE)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[byte] = 0;
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*save_update(char *save)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	tmp = malloc(sizeof(char) * ft_strlen(save) - i);
	if (!tmp)
		return (0);
	i++;
	while (save[i])
		tmp[j++] = save[i++];
	tmp[j] = '\0';
	free(save);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = all_line(fd, save);
	if (!save)
		return (0);
	line = get_line(save);
	save = save_update(save);
	return (line);
}
