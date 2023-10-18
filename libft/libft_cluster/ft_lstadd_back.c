/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:50:13 by hjeong            #+#    #+#             */
/*   Updated: 2022/01/17 17:07:26 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*llst;

	if (*lst == 0)
		*lst = new;
	else
	{
		llst = *lst;
		while (llst->next != 0)
			llst = llst->next;
		llst->next = new;
	}
}
