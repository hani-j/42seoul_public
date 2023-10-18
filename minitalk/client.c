/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:05:41 by hjeong            #+#    #+#             */
/*   Updated: 2022/08/01 08:05:42 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	send_message_to_server(char *argv1, char *argv2)
{
	int		i;
	char	c;

	while (*argv2)
	{
		i = 8;
		c = *argv2++;
		while (i)
		{
			i--;
			if ((c >> i) & 1)
				kill(ft_atoi(argv1), SIGUSR2);
			else
				kill(ft_atoi(argv1), SIGUSR1);
			usleep(150);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		send_message_to_server(argv[1], argv[2]);
		ft_putnbr_fd(getpid(), 1);
		return (0);
	}
	else
		return (0);
}
