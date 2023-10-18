/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:59:23 by hjeong            #+#    #+#             */
/*   Updated: 2022/01/17 20:59:41 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
