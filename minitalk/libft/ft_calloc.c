/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:33:10 by junhyuki          #+#    #+#             */
/*   Updated: 2022/02/22 21:18:22 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t n)
{
	void	*str;

	str = malloc(n * cnt);
	if (!str)
		return (0);
	ft_memset(str, 0, n * cnt);
	return (str);
}
