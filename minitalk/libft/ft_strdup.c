/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:32:58 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/26 21:14:21 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	copy = (char *)malloc(sizeof(char) * size + 1);
	if (!copy)
		return (0);
	while (i < size)
	{
		copy[i] = s[i];
		i++;
	}
	copy[size] = '\0';
	return (copy);
}
