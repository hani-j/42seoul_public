/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utills.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:40 by junhyuki          #+#    #+#             */
/*   Updated: 2022/10/25 11:07:53 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"

char	*remove_newline(char *line, char *set)
{
	char	**splited;
	char	*temp;

	splited = ft_split(line, set);
	if (splited[0] == NULL)
	{
		free(splited);
		return (ft_strdup(" "));
	}
	temp = splited[0];
	free(splited[1]);
	free(splited);
	return (temp);
}
