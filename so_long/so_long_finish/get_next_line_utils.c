/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:09:59 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/07 13:59:52 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gstrlen(const char *s)
{
	size_t	num;

	num = 0;
	if (s == 0)
		return (0);
	while (s[num] != 0)
		num++;
	return (num);
}

char	*ft_gstrchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_gstrjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == 0)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (0);
	join = malloc(ft_gstrlen(s1) + ft_gstrlen(s2) + 1);
	if (join == 0)
		return (0);
	while (s1[++i])
		join[i] = s1[i];
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	return (join);
}
