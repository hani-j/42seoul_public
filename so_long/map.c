/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:31:52 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/09 18:13:48 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] != '\0' && haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}

void	cep_check(t_mlxdata *data, int wid, int hei, int c)
{
	int	e;
	int	p;

	e = 0;
	p = 0;
	while (hei < data->height)
	{
		wid = 0;
		while (wid < data->width)
		{
			if (data->map[hei][wid] == 'C')
				c++;
			else if (data->map[hei][wid] == 'E')
				e++;
			else if (data->map[hei][wid] == 'P')
				p++;
			else if (data->map[hei][wid] != '1' && data->map[hei][wid] != '0')
				error_print("map format error\n");
			wid++;
		}
		hei++;
	}
	data->carrot = c;
	if (e == 0 || c == 0 || p != 1)
		error_print("role error\n");
}

void	wall_check(t_mlxdata *data)
{
	int	wid;
	int	hei;

	wid = 0;
	while (wid < data->width)
	{
		if (data->map[0][wid] != '1')
			error_print("role error\n");
		if (data->map[data->height - 1][wid] != '1')
			error_print("role error\n");
		wid++;
	}
	hei = 0;
	while (hei < data->height)
	{
		if (data->map[hei][0] != '1')
			error_print("role error\n");
		if (data->map[hei][data->width - 1] != '1')
			error_print("role error\n");
		hei++;
	}
}

void	map_check(t_mlxdata *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		if (ft_strlen(data->map[i]) != data->width)
			error_print("map format error\n");
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				data->loc.x = j;
				data->loc.y = i;
			}
			j++;
		}
		i++;
	}
}

void	map_init(char *argv, t_mlxdata *data)
{
	int		file;
	int		height;
	char	*line;
	char	*save;

	if (ft_strnstr(argv, ".ber", 4) != &argv[ft_strlen(argv) - 4])
		error_print("file format error\n");
	file = open(argv, O_RDONLY);
	line = get_next_line(file);
	data->width = ft_strlen(line) - 1;
	height = 0;
	while (line)
	{
		save = ft_strjoin(save, line);
		free(line);
		line = 0;
		line = get_next_line(file);
		height++;
	}
	data->height = height;
	data->map = ft_split(save, '\n');
	map_check(data);
	wall_check(data);
	cep_check(data, 0, 0, 0);
}
