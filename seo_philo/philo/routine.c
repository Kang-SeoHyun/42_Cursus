/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:32:05 by seokang           #+#    #+#             */
/*   Updated: 2023/04/11 21:39:48 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_fork(t_philo *philo)
{
	t_info	    *info;
	int			philo_count;

	info = philo->info;
	philo_count = info->philo_count;
	if (philo->id % 2)
	{
		pthread_mutex_lock(&info->m_forks[philo->id]);
		print_state(info, philo->id, PICKUP);
		pthread_mutex_lock(&info->m_forks[(philo->id + 1) % philo_count]);
		print_state(info, philo->id, PICKUP);
	}
	else
	{
		pthread_mutex_lock(&info->m_forks[(philo->id + 1) % philo_count]);
		print_state(info, philo->id, PICKUP);
		pthread_mutex_lock(&info->m_forks[philo->id]);
		print_state(info, philo->id, PICKUP);
	}
}

static void	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->m_eat[philo->id]);
	info->last_eat_time[philo->id] = get_time(0);
	++info->eat_cnt[philo->id];
	pthread_mutex_unlock(&info->m_eat[philo->id]);
	print_state(info, philo->id, EAT);
	smart_timer(info->time_to_eat);
}

static void	put_down(t_philo *philo)
{
	t_info	*info;
	int		philo_count;

	info = philo->info;
	philo_count = info->philo_count;
	if (philo->id % 2)
	{
		pthread_mutex_unlock(&info->m_forks[(philo->id + 1) % philo_count]);
		pthread_mutex_unlock(&info->m_forks[philo->id]);
	}
	else
	{
		pthread_mutex_unlock(&info->m_forks[philo->id]);
		pthread_mutex_unlock(&info->m_forks[(philo->id + 1) % philo_count]);
	}
}

void    *routine(void *arg)
{
    t_philo	*philo;
    t_info	*info;

    philo = (t_philo *)arg;
    info = philo->info;
    while (info->start_time == 0)
        smart_timer(10);
    while (1)
    {
        take_fork(philo);
		eating(philo);
		put_down(philo);
		print_state(info, philo->id, SLEEP);
		smart_timer(info->time_to_sleep);
		print_state(info, philo->id, THINK);
	}
}
