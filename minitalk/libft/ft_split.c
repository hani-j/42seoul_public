/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:12:45 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/26 21:49:37 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_splitlen(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (len);
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

static char	**ft_splitfree(char **split, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		slen;
	int		sindex;
	char	**split;

	i = 0;
	sindex = 0;
	split = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (split == 0)
		return (0);
	while (sindex < ft_count(s, c))
	{
		while (s[i] == c)
			i++;
		slen = ft_splitlen(&s[i], c);
		split[sindex] = malloc(sizeof(char) * (slen + 1));
		if (split[sindex] == 0)
			return (ft_splitfree(split, sindex));
		ft_strlcpy(split[sindex], &s[i], slen + 1);
		i = i + slen + 1;
		sindex++;
	}
	split[sindex] = 0;
	return (split);
}
