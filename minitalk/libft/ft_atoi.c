/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:33:14 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/25 02:29:35 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	istr;

	i = 0;
	num = 1;
	istr = 0;
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				num *= -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			istr = (istr * 10) + (str[i] - '0');
			i++;
		}
		return (istr * num);
	}
	return (0);
}
