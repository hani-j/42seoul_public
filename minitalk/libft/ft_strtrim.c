/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:34:20 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/26 19:33:55 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	int		start;
	int		end;

	start = 0;
	if (!set)
		return (ft_strdup((char *)s1));
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
	{
		if (end - 1 < 1)
			break ;
		end--;
	}
	if (start >= end)
		return (ft_strdup(""));
	copy = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!copy)
		return (0);
	ft_strlcpy(copy, &s1[start], end - start + 1);
	return (copy);
}
