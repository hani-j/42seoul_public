/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:39:10 by junhyuki          #+#    #+#             */
/*   Updated: 2022/10/26 10:06:03 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"

static void	is_digit(char *line, int *i)
{
	while (line[*i] >= '0' && line[*i] <= '9')
		++(*i);
}

static int	is_valid_fc(char *line, int i, int num_count, int comma_count)
{
	int	k;

	k = 0;
	while (is_space(line[i]))
		++i;
	while (k < 2)
	{
		is_digit(line, &i);
		++num_count;
		while (is_space(line[i]) || line[i] == ',')
		{
			if (line[i] == ',')
				++comma_count;
			++i;
		}
		++k;
	}
	is_digit(line, &i);
	++num_count;
	while (i != (int)ft_strlen(line) - 1 && is_space(line[i]))
		++i;
	if (i == (int)ft_strlen(line) - 1 && comma_count == 2 && num_count == 3)
		return (1);
	return (0);
}

int	get_fc(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		++i;
	if (line[i] == 'F' || line[i] == 'C')
		++i;
	else
		return (0);
	if (!is_space(line[i]))
		print_error_and_exit("wrong information\n");
	if (!is_valid_fc(line, i, 0, 0))
		print_error_and_exit("wrong information\n");
	return (1);
}
