/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morethan5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:07:23 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/23 10:08:37 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_sort_atob(t_stack *a, t_stack *b, int chunk)
{
	int	num;

	num = 0;
	while (a->current_count)
	{
		if (a->topnode->index > num + chunk)
			ra_rb(a, 'a');
		else
		{
			if (a->topnode->index <= num)
				pa_pb(b, a, 'b');
			else
			{
				pa_pb(b, a, 'b');
				ra_rb(b, 'b');
			}
			num++;
		}
	}
}

void	rra_sort_atob(t_stack *a, t_stack *b, int chunk)
{
	int	num;

	num = 0;
	while (a->current_count)
	{
		if (a->topnode->index > num + chunk)
		{
			if (num < a->current_count / 2)
				rra_rrb(a, 'a');
			else
				ra_rb(a, 'a');
		}
		else
		{
			if (a->topnode->index <= num)
				pa_pb(b, a, 'b');
			else
			{
				pa_pb(b, a, 'b');
				ra_rb(b, 'b');
			}
			num++;
		}
	}
}

void	sort_btoa(t_stack *astack, t_stack *bstack)
{
	int	node_index;

	while (bstack->current_count)
	{
		node_index = search_node_index(bstack, bstack->current_count - 1);
		if (node_index < bstack->current_count / 2)
		{
			while (bstack->topnode->index != bstack->current_count - 1)
				ra_rb(bstack, 'b');
		}
		else
		{
			while (bstack->topnode->index != bstack->current_count - 1)
				rra_rrb(bstack, 'b');
		}
		pa_pb(astack, bstack, 'a');
	}
}

int	rra_check(t_stack *stack)
{
	t_node	*node;
	int		i;
	int		count;

	i = 0;
	count = 0;
	node = stack->tailnode;
	while (i < stack->current_count / 3)
	{
		if (node->index < stack->current_count / 3)
			count++;
		node = node->prenode;
		i++;
	}
	if (count > stack->current_count / 4)
		return (1);
	return (0);
}

void	morethan5(t_stack *astack, t_stack *bstack)
{
	int	chunk;
	int	count;

	count = astack->current_count;
	chunk = 0.000000053 * count * count + 0.03 * count + 14.5;
	if (rra_check(astack))
		rra_sort_atob(astack, bstack, chunk);
	else
		ra_sort_atob(astack, bstack, chunk);
	sort_btoa(astack, bstack);
}
