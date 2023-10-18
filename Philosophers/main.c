/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:32:53 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/28 17:10:40 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_rule	rule;

	if (!parsing(argc, argv, &rule))
	{
		printf("FAIL\n");
		return (0);
	}
	philo_run(&rule);
	return (0);
}
