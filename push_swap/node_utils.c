/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:19:20 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/23 10:08:38 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == 0)
		exit(1);
	node->index = index;
	node->prenode = 0;
	node->nextnode = 0;
	return (node);
}

void	push_node_front(t_stack *stack, t_node *newnode)
{
	if (!newnode)
		return ;
	newnode->nextnode = stack->topnode;
	if (stack->topnode == 0)
		stack->tailnode = newnode;
	else
		stack->topnode->prenode = newnode;
	stack->topnode = newnode;
	stack->current_count += 1;
	return ;
}

void	push_node_back(t_stack *stack, t_node *newnode)
{
	if (!newnode)
		return ;
	newnode->prenode = stack->tailnode;
	if (stack->topnode == 0)
		stack->topnode = newnode;
	else
		stack->tailnode->nextnode = newnode;
	stack->tailnode = newnode;
	stack->current_count += 1;
	return ;
}

t_node	*pop_node_front(t_stack *stack)
{
	t_node	*popnode;

	popnode = stack->topnode;
	if (stack->topnode && stack->topnode->nextnode)
	{
		stack->topnode = stack->topnode->nextnode;
		stack->topnode->prenode = 0;
		popnode->nextnode = 0;
	}
	else
	{
		stack->topnode = 0;
		stack->tailnode = 0;
	}
	stack->current_count -= 1;
	return (popnode);
}

t_node	*pop_node_back(t_stack *stack)
{
	t_node	*popnode;

	popnode = stack->tailnode;
	if (stack->tailnode && stack->tailnode->prenode)
	{
		stack->tailnode = stack->tailnode->prenode;
		stack->tailnode->nextnode = 0;
		popnode->prenode = 0;
	}
	else
	{
		stack->topnode = 0;
		stack->tailnode = 0;
	}
	stack->current_count -= 1;
	return (popnode);
}
