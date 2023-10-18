/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:06:31 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/23 10:08:09 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	str_check(t_stack *astack, t_stack *bstack, char *str)
{
	if (ft_strcmp("sa\n", str) == 0)
		sa_sb(astack, 'a');
	else if (ft_strcmp("sb\n", str) == 0)
		sa_sb(bstack, 'b');
	else if (ft_strcmp("ss\n", str) == 0)
		ss(astack, bstack);
	else if (ft_strcmp("pa\n", str) == 0)
		pa_pb(astack, bstack, 'a');
	else if (ft_strcmp("pb\n", str) == 0)
		pa_pb(bstack, astack, 'b');
	else if (ft_strcmp("ra\n", str) == 0)
		ra_rb(astack, 'a');
	else if (ft_strcmp("rb\n", str) == 0)
		ra_rb(bstack, 'b');
	else if (ft_strcmp("rr\n", str) == 0)
		rr(astack, bstack);
	else if (ft_strcmp("rra\n", str) == 0)
		rra_rrb(astack, 'a');
	else if (ft_strcmp("rrb\n", str) == 0)
		rra_rrb(bstack, 'b');
	else if (ft_strcmp("rrr\n", str) == 0)
		rrr(astack, bstack);
	else
		print_error();
}

void	s_sorted_check(t_stack *astack, t_stack *bstack)
{
	t_node	*node;
	int		check;

	check = 0;
	node = astack->topnode;
	if (!bstack->topnode)
	{
		while (node->nextnode)
		{
			if (node->index > node->nextnode->index)
				check++;
			node = node->nextnode;
		}
		if (check == 0)
		{
			write(1, "OK\n", 3);
			exit(0);
		}
	}
	write(1, "KO\n", 3);
	exit(1);
}

void	get_command(t_stack *astack, t_stack *bstack)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		str_check(astack, bstack, str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int argc, char **argv)
{
	t_stack	*astack;
	t_stack	*bstack;
	int		*arr;
	int		arrcount;

	if (argc < 2)
		exit (1);
	astack = create_stack();
	bstack = create_stack();
	arrcount = arr_count(argv);
	arr = malloc(sizeof(int) * arrcount + 1);
	if (!arr)
		exit(1);
	set_array(astack, argv, arr, arrcount);
	get_command(astack, bstack);
	s_sorted_check(astack, bstack);
}
