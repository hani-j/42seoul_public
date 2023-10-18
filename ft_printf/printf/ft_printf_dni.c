/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dni.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:02:30 by hjeong            #+#    #+#             */
/*   Updated: 2022/04/29 13:03:26 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_dni(va_list ap)
{
	int		d;
	char	*s;

	d = va_arg(ap, int);
	s = ft_itoa(d);
	ft_putstr(s);
	free(s);
	s = NULL;
	return (ft_digit(d));
}

int	ft_digit(int n)
{
	int		digit;
	long	ln;

	ln = n;
	digit = 0;
	if (ln == 0)
		return (1);
	if (ln < 0)
	{
		ln *= -1;
		digit++;
	}
	while (ln > 0)
	{
		ln /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		i;
	long	ln;

	ln = n;
	i = ft_digit(n);
	a = malloc(sizeof(char) * i + 1);
	ft_memset(a, 0, i + 1);
	if (a == 0)
		return (0);
	if (ln < 0)
	{
		a[0] = '-';
		ln *= -1;
	}
	i--;
	while (i >= 0)
	{
		if (a[i] != '-')
			a[i] = (ln % 10) + '0';
		ln /= 10;
		i--;
	}
	return (a);
}
