/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:32:49 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/25 15:46:09 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static int	init_philo(t_param *param)
{
	int	i;

	param->philo = malloc(sizeof(t_philo) * param->rule->num_of_philo);
	if (!param->philo)
		return (FAIL);
	i = 0;
	while (i < param->rule->num_of_philo)
	{
		param->philo[i].param = param;
		param->philo[i].eat_count = 0;
		param->philo[i].start_starving_time = get_time(param);
		param->philo[i].left_fork = &param->forks[i];
		param->philo[i].right_fork = &param->forks[(i + 1) \
			% param->rule->num_of_philo];
		++i;
	}
	return (SUCCESS);
}

int	init_param(t_param *param, t_rule *rule)
{
	int	i;

	param->rule = rule;
	param->forks = malloc(sizeof(pthread_mutex_t) * rule->num_of_philo);
	if (!param->forks)
		return (FAIL);
	pthread_mutex_init(&param->print_lock, NULL);
	pthread_mutex_init(&param->is_dining_lock, NULL);
	pthread_mutex_init(&param->get_time_lock, NULL);
	param->start_time = get_time(param);
	i = 0;
	while (i < rule->num_of_philo)
	{
		pthread_mutex_init(&param->forks[i], NULL);
		++i;
	}
	param->tids = malloc(sizeof(pthread_t) * rule->num_of_philo);
	if (!param->tids)
		return (FAIL);
	init_philo(param);
	return (SUCCESS);
}
