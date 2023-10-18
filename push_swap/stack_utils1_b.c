/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:38:14 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/23 10:10:40 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_count(char **argv)
{
	char	**split;
	int		num;
	int		i;
	int		j;

	i = 1;
	num = 0;
	while (argv[i])
	{
		split = ft_split(argv[i++], ' ');
		if (!split)
			exit(1);
		j = 0;
		while (split[j++])
			num++;
		ft_splitfree(split, j);
	}
	return (num);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	rr(t_stack *astack, t_stack *bstack)
{
	push_node_back(astack, pop_node_front(astack));
	push_node_back(bstack, pop_node_front(bstack));
}

void	rra_rrb(t_stack *stack, char c)
{
	push_node_front(stack, pop_node_back(stack));
	c = 0;
}

void	rrr(t_stack *astack, t_stack *bstack)
{
	push_node_front(astack, pop_node_back(astack));
	push_node_front(bstack, pop_node_back(bstack));
}
