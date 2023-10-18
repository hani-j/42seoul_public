/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:24:18 by hjeong            #+#    #+#             */
/*   Updated: 2022/04/26 14:48:15 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	ft_printf_s(va_list ap)
{
	char	*str;
	int		n;

	str = va_arg(ap, char *);
	n = 0;
	if (str == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[n])
	{
		write(1, &str[n], 1);
		n++;
	}
	return (n);
}
