/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:49:54 by hjeong            #+#    #+#             */
/*   Updated: 2022/01/17 18:08:14 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*lstmap;
	t_list	*lstmap_n;

	lstmap = ft_lstnew(f(lst->content));
	if (lstmap == 0)
		return (0);
	lstmap_n = lstmap;
	while (lst->next)
	{
		lst = lst->next;
		lstmap_n->next = ft_lstnew(f(lst->content));
		if (lstmap_n == 0)
		{
			ft_lstclear(&lstmap, del);
			return (0);
		}
		lstmap_n = lstmap_n->next;
	}
	return (lstmap);
}
