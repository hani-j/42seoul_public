/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:54:58 by hjeong            #+#    #+#             */
/*   Updated: 2022/01/17 18:31:09 by hjeong           ###   ########.fr       */
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
