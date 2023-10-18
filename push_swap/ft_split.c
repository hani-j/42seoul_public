/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:00:22 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/23 10:08:09 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

int	ft_count(char const *s, char c)
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
	if (count == 0)
		print_error();
	return (count);
}

int	ft_splitlen(char const *s, char c)
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

char	**ft_splitfree(char **split, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(split[i]);
		split[i] = 0;
		i++;
	}
	free(split);
	split = 0;
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
		ft_strlcpy(split[sindex], (char *)&s[i], slen + 1);
		i = i + slen + 1;
		sindex++;
	}
	split[sindex] = 0;
	return (split);
}
