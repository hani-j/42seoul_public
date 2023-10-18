/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:26:14 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/26 02:51:28 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strnlen(char *s, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n && s[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;

	destlen = my_strnlen(dest, size);
	if (size < destlen)
		return (destlen + ft_strlen(src));
	return (destlen + ft_strlcpy(dest + destlen, src, size - destlen));
}
