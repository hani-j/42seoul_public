/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:22:39 by hogkim            #+#    #+#             */
/*   Updated: 2022/09/14 20:22:39 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdlib.h>

void	check_arguments(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Wrong Arguments\n", 2);
		exit(EXIT_FAILURE);
	}
}
