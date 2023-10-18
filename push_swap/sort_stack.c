/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:14:51 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/23 10:10:34 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_node_index(t_stack *stack, int num)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->topnode;
	while (i < stack->current_count)
	{
		if (node->index == num)
			return (i);
		node = node->nextnode;
		i++;
	}
	return (0);
}

void	lessthan5(t_stack *astack, t_stack *bstack)
{
	while (astack->current_count > 3)
	{
		while (astack->topnode->index >= 2)
			ra_rb(astack, 'a');
		pa_pb(bstack, astack, 'b');
	}
	sort_stack(astack, bstack);
	pa_pb(astack, bstack, 'a');
	pa_pb(astack, bstack, 'a');
	if (astack->topnode->index > astack->topnode->nextnode->index)
		sa_sb(astack, 'a');
}

void	set012(t_stack *stack, int	*arr)
{
	t_node	*node;
	int		i;

	node = stack->topnode;
	i = 0;
	while (i < 3)
	{
		arr[i++] = node->index;
		node = node->nextnode;
	}
}

void	lessthan3(t_stack *astack)
{
	int	*arr;

	arr = malloc(sizeof(int) * 3);
	if (!arr)
		exit(1);
	set012(astack, arr);
	if (arr[0] < arr[1] && arr[1] < arr[2])
		return ;
	if (arr[0] < arr[1])
	{
		rra_rrb(astack, 'a');
		if (arr[0] < arr[2])
			sa_sb(astack, 'a');
		return ;
	}
	if (arr[0] < arr[2])
		sa_sb(astack, 'a');
	else
	{
		ra_rb(astack, 'a');
		if (arr[1] > arr[2])
			sa_sb(astack, 'a');
	}
	free(arr);
}

void	sort_stack(t_stack *astack, t_stack *bstack)
{
	if (astack->current_count <= 2)
		sa_sb(astack, 'a');
	else if (astack->current_count == 3)
		lessthan3(astack);
	else if (astack->current_count <= 5)
		lessthan5(astack, bstack);
	else
		morethan5(astack, bstack);
}
