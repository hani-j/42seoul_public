/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:22:42 by hogkim            #+#    #+#             */
/*   Updated: 2022/09/19 17:15:19 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

int	g_exit_status;

void	prompt_loop(t_all_data *all_data)
{
	char	*line;

	while (1)
	{
		line = readline("minishell > ");
		if (line)
		{
			set_handler_for_ignore();
			g_exit_status = process_line(all_data, line);
			free(line);
			line = NULL;
		}
		else
		{
			ft_putstr_fd("exit\n", 1);
			exit(0);
		}
	}
}
