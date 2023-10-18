/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:30:42 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/07 14:13:07 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	num;

	num = 0;
	if (s == 0)
		return (0);
	while (s[num] != '\0')
		num++;
	return (num);
}

char	*ft_strjoin(char *s1, char *s2)
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
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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

char	*ft_strdup(const char *s)
{
	char	*c;
	int		i;
	int		j;

	i = 0;
	while (s[i])
		i++;
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (c == 0)
		return (0);
	j = 0;
	while (s[j])
	{
		c[j] = s[j];
		j++;
	}
	c[j] = '\0';
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	strlen;

	i = 0;
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (0);
	if (strlen - start < len)
		len = strlen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	while (len-- > 0 && start + i < strlen)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
