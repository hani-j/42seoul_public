/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:57:03 by hjeong            #+#    #+#             */
/*   Updated: 2022/01/12 17:28:50 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(dest);
	if (i > size)
		return (size + ft_strlen(src));
	else
	{
		while (*src != '\0' && i + 1 < size)
		{
			*(dest + i) = *src++;
			i++;
		}
		*(dest + i) = '\0';
	}
	while (*src != '\0')
	{
		src++;
		i++;
	}
	return (i);
}
