/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:18:14 by seokang           #+#    #+#             */
/*   Updated: 2023/04/03 18:18:15 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_died(t_info *info, int philo_id)
{
	size_t	time_interval;

	pthread_mutex_lock(&info->m_eat[philo_id]);
	if (info->eat_cnt[philo_id] == 0)
		time_interval = get_time(info->start_time);
	else
		time_interval = get_time(info->last_eat_time[philo_id]);
	pthread_mutex_unlock(&info->m_eat[philo_id]);
	if (time_interval > size_t)(info->time_to_die)
		return (true);
	return (false);
}

static bool	check_done(t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->philo_count)
	{
		pthread_mutex_lock(&info->m_eat[idx]);
		if (info->eat_cnt[idx] < info->must_eat)
		{
			pthread_mutex_unlock(&info->m_eat[idx]);
			return (false);
		}
		pthread_mutex_unlock(&info->m_eat[idx]);
		idx++;
	}
	return (true);
}

static void	ft_manage(t_info *info)
{
	int		idx;
	bool	is_dead;

	info->start_time = get_time();
	is_dead = false;
	while (true)
	{
		idx = -1;
		while (is_dead == false && ++idx < info->philo_count)
			is_dead = check_died(info, idx);
		if (is_dead)
		{
			print_died(&info->m_print, info->start_time, idx, DIE);
			break ;
		}
		if (info->must_eat && check_done(info))
		{
			print_done(&info->m_print);
			break ;
		}
	}
}

void	simulate(t_info *info)
{
	int		idx;
	t_philo	philos[MAX_PHILO];

	idx = 0;
	while (idx < info->philo_count)
	{
		//저거 &앞에 괄호호
		pthread_mutex_init(&(info->m_eat[idx]), NULL);
		pthread_mutex_init(&(info->m_fork[idx]), NULL);
		philos[idx].id = idx;
		philos[idx].info = info;
		if (pthread_create(&philos[idx].thread, NULL, \
			함수, (void *)(philos + idx)) != 0)
			break;
		idx++;
	}
	pthread_mutex_init(&(info->m_print), NULL);
	if (idx == info->philo_count)
		ft_manage(info);
	pthread_mutex_destroy(&(info->m_print))
	while (--idx >= 0)
	{
		pthread_mutex_destroy(&manager->m_eat[idx]);
		pthread_mutex_destroy(&manager->m_forks[idx]);
	}
}
