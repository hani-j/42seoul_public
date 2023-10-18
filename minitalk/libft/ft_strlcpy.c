/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:26:16 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/26 21:54:35 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = ft_strlen(src);
	if (size == 0)
		return (a);
	while (src[i] != '\0' && (i + 1) < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (a);
}
