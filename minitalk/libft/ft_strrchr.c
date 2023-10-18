/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:28:34 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/25 01:48:36 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*start;
	int		i;

	i = 0;
	start = (char *)s;
	while (*start)
	{
		start++;
		i++;
	}
	if (c == 0)
		return (start);
	while (i >= 0)
	{
		if (*start == (char)c)
			return (start);
		else
		{
			i--;
			start--;
		}
	}
	return (0);
}
