/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:01:42 by hjeong            #+#    #+#             */
/*   Updated: 2022/01/17 11:27:24 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return (&((unsigned char *)s)[i]);
		}
		i++;
	}
	if (c != '\0')
		return (NULL);
	return (&((unsigned char *)s)[i]);
}
