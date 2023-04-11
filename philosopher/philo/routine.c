/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:55:38 by seokang           #+#    #+#             */
/*   Updated: 2023/04/11 22:49:54 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	pick_up(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx_left);
	if (print_state(philo, philo->idx, PICKUP, 0))
		return (ERROR);
	pthread_mutex_lock(philo->mtx_right);
	if (print_state(philo, philo->idx, PICKUP, 0))
		return (ERROR);
	return (SUCCESS);
}

static int	eating(t_philo *philo, t_arg *arg)
{
	if (print_state(philo, philo->idx, EAT, EATTING))
		return (ERROR);
	smart_timer(arg->eat_time);
	return (SUCCESS);
}

static int	put_down(t_philo *philo, t_arg *arg)
{
	pthread_mutex_unlock(philo->mtx_right);
	pthread_mutex_unlock(philo->mtx_left);
	if (print_state(philo, philo->idx, SLEEP, 0))
		return (ERROR);
	smart_timer(arg->sleep_time);
	if (print_state(philo, philo->idx, THINK, 0))
		return (ERROR);
	usleep(50);
	return (SUCCESS);
}

void	*action(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(&philo->info->mtx_print);
	(*philo).last_eat_t = get_time();
	pthread_mutex_unlock(&philo->info->mtx_print);
	if (philo->idx % 2 != 0)
		smart_timer(philo->info->arg.eat_time / 2);
	while (!pick_up(philo)
		&& !eating(philo, &philo->info->arg)
		&& !put_down(philo, &philo->info->arg));
	return (NULL);
}
