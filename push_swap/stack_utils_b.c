/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:32:51 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/23 10:10:36 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == 0)
		return (0);
	stack->current_count = 0;
	stack->topnode = 0;
	stack->tailnode = 0;
	return (stack);
}

void	sa_sb(t_stack *stack, char c)
{
	t_node	*first_node;
	t_node	*second_node;

	first_node = pop_node_front(stack);
	second_node = pop_node_front(stack);
	push_node_front(stack, first_node);
	push_node_front(stack, second_node);
	c = 0;
}

void	ss(t_stack *astack, t_stack *bstack)
{
	t_node	*first_node;
	t_node	*second_node;

	first_node = pop_node_front(astack);
	second_node = pop_node_front(astack);
	push_node_front(astack, first_node);
	push_node_front(astack, second_node);
	first_node = pop_node_front(bstack);
	second_node = pop_node_front(bstack);
	push_node_front(bstack, first_node);
	push_node_front(bstack, second_node);
}

void	pa_pb(t_stack *astack, t_stack *bstack, char c)
{
	if (bstack->topnode == 0)
		return ;
	push_node_front(astack, pop_node_front(bstack));
	c = 0;
}

void	ra_rb(t_stack *stack, char c)
{
	push_node_back(stack, pop_node_front(stack));
	c = 0;
}
