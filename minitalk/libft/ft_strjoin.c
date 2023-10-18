/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:33:54 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/26 19:33:12 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!copy)
		return (0);
	ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	ft_strlcpy(copy + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (copy);
}
