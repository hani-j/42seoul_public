/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:39:35 by junhyuki          #+#    #+#             */
/*   Updated: 2022/10/24 14:39:35 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <unistd.h>
#include <stdlib.h>

void	put_string_fd(char *str, int fd)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	write (fd, str, len);
}

void	print_error_and_exit(char *str)
{
	put_string_fd("Error\n", 2);
	put_string_fd(str, 2);
	exit(1);
}
