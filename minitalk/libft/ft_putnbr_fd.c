/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 02:46:13 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/26 21:48:24 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_putnb(int n, int fd)
{
	if (n >= 10)
	{
		my_putnb(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	my_putnb(n, fd);
}
