/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:06:02 by hjeong            #+#    #+#             */
/*   Updated: 2022/08/01 08:06:03 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	receive_message(int sign)
{
	static char		c;
	static int		i;

	if (sign == SIGUSR2)
		c |= 1;
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_putstr_fd("server Pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, receive_message);
	signal(SIGUSR2, receive_message);
	while (1)
		pause();
	return (0);
}
