/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:38:14 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/23 10:10:42 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *astack, t_stack *bstack)
{
	push_node_back(astack, pop_node_front(astack));
	push_node_back(bstack, pop_node_front(bstack));
	write(1, "rr\n", 3);
}

void	rra_rrb(t_stack *stack, char c)
{
	push_node_front(stack, pop_node_back(stack));
	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *astack, t_stack *bstack)
{
	push_node_front(astack, pop_node_back(astack));
	push_node_front(bstack, pop_node_back(bstack));
	write(1, "rrr\n", 4);
}
