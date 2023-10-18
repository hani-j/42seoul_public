/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_astack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:34:14 by hjeong            #+#    #+#             */
/*   Updated: 2022/06/23 10:10:30 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		print_error();
	exit(1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	istr;

	i = 0;
	minus = 1;
	istr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		minus *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error();
		istr = (istr * 10) + (str[i] - '0');
		i++;
	}
	istr *= minus;
	if (str[i] != '\0' || istr > 2147483647 || istr < -2147483648)
		print_error();
	return ((int)istr);
}

void	set_astack(t_stack *astack, int *arr, int c)
{
	int	index;
	int	i;
	int	j;

	i = 0;
	while (i < c)
	{
		index = 0;
		j = 0;
		while (j < c)
		{
			if (arr[i] == arr[j] && i != j)
				print_error();
			if (arr[i] > arr[j])
				index++;
			j++;
		}
		push_node_back(astack, create_node(index));
		i++;
	}
}

void	sort_check(int *arr, int num)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < num - 1)
	{
		if (arr[i] > arr[i + 1])
			check++;
		i++;
	}
	if (check == 0 || (check == 0 && i <= 1))
		exit(1);
}

void	set_array(t_stack *astack, char **argv, int *arr, int c)
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
		while (split[j])
			arr[num++] = ft_atoi(split[j++]);
		ft_splitfree(split, j);
	}
	set_astack(astack, arr, c);
	free(arr);
}
