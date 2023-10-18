/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:28:59 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/09 19:43:09 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

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

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		i;
	long	ln;

	ln = n;
	i = ft_digit(n);
	a = malloc(sizeof(char) * i + 1);
	if (a == 0)
		return (0);
	ft_memset(a, 0, i);
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
