/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:12:55 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/25 02:29:34 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit(int n)
{
	int		digit;
	long	ln;

	digit = 0;
	ln = n;
	if (n == 0)
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
	a = ft_calloc(sizeof(char), i + 1);
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
