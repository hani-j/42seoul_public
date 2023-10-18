/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:02:30 by hjeong            #+#    #+#             */
/*   Updated: 2022/04/29 13:13:40 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(va_list ap)
{
	unsigned int	u;
	char			*s;

	u = va_arg(ap, unsigned int);
	s = ft_itoa_u(u);
	ft_putstr(s);
	free(s);
	s = NULL;
	return (ft_digit_u(u));
}

int	ft_digit_u(unsigned int n)
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

char	*ft_itoa_u(unsigned int n)
{
	char	*a;
	int		i;
	long	ln;

	ln = n;
	i = ft_digit_u(n);
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
