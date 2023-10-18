/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:29:57 by hjeong            #+#    #+#             */
/*   Updated: 2022/04/29 12:49:18 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_specifier(va_list ap, const char *str)
{
	int	num;

	num = 0;
	if (*str == 'c')
		num = ft_printf_c(ap);
	if (*str == 's')
		num = ft_printf_s(ap);
	if (*str == 'p')
		return (ft_printf_p(ap));
	if (*str == 'd' || *str == 'i')
		return (ft_printf_dni(ap));
	if (*str == 'u')
		return (ft_printf_u(ap));
	if (*str == 'x' || *str == 'X')
		return (ft_printf_xupx(ap, str));
	if (*str == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (num);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		byte;

	byte = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			byte += ft_check_specifier(ap, ++str);
		else
		{
			write(1, str, 1);
			byte++;
		}
		str++;
	}
	va_end(ap);
	return (byte);
}
