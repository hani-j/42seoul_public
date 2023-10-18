/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:33:02 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/26 18:12:25 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *set, size_t n)
{
	size_t	i;
	size_t	j;
	char	*copy;

	i = 0;
	copy = (char *)s1;
	if (set[i] == '\0')
		return (copy);
	while (i < n && copy[i] != '\0')
	{
		j = 0;
		if (copy[i] == set[j])
		{
			while ((copy[i + j] == set[j]) && (set[j] != '\0') && (i + j < n))
				j++;
			if (set[j] == '\0')
				return (&copy[i]);
		}
		i++;
	}
	return (0);
}
