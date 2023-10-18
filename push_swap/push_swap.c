/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:05:41 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/23 10:08:40 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

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
	sort_check(arr, arrcount);
	sort_stack(astack, bstack);
}
