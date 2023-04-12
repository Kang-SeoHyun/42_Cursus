/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:55:38 by seokang           #+#    #+#             */
/*   Updated: 2023/04/12 18:46:20 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	pick_up(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_hand);
		if (print_state(philo, philo->id, PICKUP, 0))
			return (ERROR);
		pthread_mutex_lock(philo->left_hand);
		if (print_state(philo, philo->id, PICKUP, 0))
			return (ERROR);
	}
	else
	{
		pthread_mutex_lock(philo->left_hand);
		if (print_state(philo, philo->id, PICKUP, 0))
			return (ERROR);
		pthread_mutex_lock(philo->right_hand);
		if (print_state(philo, philo->id, PICKUP, 0))
			return (ERROR);
	}
	return (SUCCESS);
}

static int	eating(t_philo *philo, t_arg *arg)
{
	if (print_state(philo, philo->id, EAT, EATTING))
		return (ERROR);
	msleep(arg->time_to_eat);
	return (SUCCESS);
}

static int	put_down(t_philo *philo, t_arg *arg)
{
	if(philo->id % 2)
	{
		pthread_mutex_unlock(philo->right_hand);
		pthread_mutex_unlock(philo->left_hand);
	}
	else
	{
		pthread_mutex_unlock(philo->left_hand);
		pthread_mutex_unlock(philo->right_hand);
	}
	if (print_state(philo, philo->id, SLEEP, 0))
		return (ERROR);
	msleep(arg->time_to_sleep);
	if (print_state(philo, philo->id, THINK, 0))
		return (ERROR);
	usleep(50);
	return (SUCCESS);
}

void	*action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->info->m_print);
	(*philo).last_eat_t = get_time();
	pthread_mutex_unlock(&philo->info->m_print);
	if (philo->id % 2 != 0)
		msleep(5);
	while (!pick_up(philo) \
		&& !eating(philo, &philo->info->arg) \
		&& !put_down(philo, &philo->info->arg));
	return (NULL);
}
