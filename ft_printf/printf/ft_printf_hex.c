/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:02:41 by hjeong            #+#    #+#             */
/*   Updated: 2022/04/29 12:40:45 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(va_list ap)
{
	size_t	p;

	p = (size_t)va_arg(ap, void *);
	write(1, "0x", 2);
	ft_puthex(p, "0123456789abcdef");
	return (ft_hexlen(p) + 2);
}

int	ft_printf_xupx(va_list ap, const char *str)
{
	unsigned int	x;
	char			*hex;

	if (*str == 'x')
		hex = "0123456789abcdef";
	if (*str == 'X')
		hex = "0123456789ABCDEF";
	x = va_arg(ap, int);
	ft_puthex(x, hex);
	return (ft_hexlen(x));
}

int	ft_hexlen(size_t nb)
{
	int	n;

	n = 1;
	while (nb > 15)
	{
		nb /= 16;
		n++;
	}
	return (n);
}

void	ft_puthex(size_t nb, char *hex)
{
	char	c;

	if (nb > 15)
		ft_puthex(nb / 16, hex);
	c = hex[nb % 16];
	write(1, &c, 1);
}
