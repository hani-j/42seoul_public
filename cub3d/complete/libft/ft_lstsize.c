/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:28:33 by hogkim            #+#    #+#             */
/*   Updated: 2022/10/24 14:35:56 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*p;

	if (!lst)
		return (0);
	p = lst;
	i = 1;
	while (p->next)
	{
		p = p->next;
		i++;
	}
	return (i);
}
