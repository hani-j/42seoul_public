/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:33:37 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/25 18:46:42 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	strlen;

	i = 0;
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
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
