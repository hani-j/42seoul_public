/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:56:53 by hjeong            #+#    #+#             */
/*   Updated: 2022/04/16 11:56:27 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*all_line(int fd, char *save)
{
	char	*buffer;
	int		byte;

	byte = BUFFER_SIZE;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(save, '\n') && byte == BUFFER_SIZE)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			free(save);
			return (0);
		}
		buffer[byte] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_line(char *save)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save[i])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (0);
	while (save[j] && save[j] != '\n')
	{
		line[j] = save[j];
		j++;
	}
	if (save[j] == '\n')
	{
		line[j] = save[i];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*save_update(char *save)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	i++;
	while (save[i])
		save[j++] = save[i++];
	save[j] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	save[fd] = all_line(fd, save[fd]);
	if (!save[fd])
		return (0);
	line = get_line(save[fd]);
	save[fd] = save_update(save[fd]);
	return (line);
}
