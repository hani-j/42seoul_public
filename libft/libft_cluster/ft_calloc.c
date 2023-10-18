/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:13:19 by hjeong            #+#    #+#             */
/*   Updated: 2022/01/15 12:27:17 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cal;

	cal = (char *)malloc(size * nmemb);
	if (cal == 0)
		return (0);
	ft_memset(cal, 0, nmemb * size);
	return (cal);
}
