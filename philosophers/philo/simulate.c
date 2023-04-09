/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:18:14 by seokang           #+#    #+#             */
/*   Updated: 2023/04/04 21:20:55 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_alive(t_info *info, int philo_id)
{
	size_t	time_interval;

	pthread_mutex_lock(&info->m_eat[philo_id]);
	if (info->eat_cnt[philo_id] == 0)
		time_interval = get_time(info->start_time);
	else
		time_interval = get_time(info->last_eat_time[philo_id]);
	pthread_mutex_unlock(&info->m_eat[philo_id]);
	if (time_interval > (size_t)(info->time_to_die))
		return (1); //죽었으면
	return (0); //살았으면
}

static int	check_finish(t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->philo_count)
	{
		pthread_mutex_lock(&info->m_eat[idx]);
		if (info->eat_cnt[idx] < info->must_eat)
		{
			pthread_mutex_unlock(&info->m_eat[idx]);
			return (0);
		}
		pthread_mutex_unlock(&info->m_eat[idx]);
		idx++;
	}
	return (1); //끝났으면
}

static void	ft_manage(t_info *info)
{
	int		idx;
	int		is_dead;

	info->start_time = get_time(0);
	is_dead = 0;
	while (1)
	{
		idx = -1;
		while (!(is_dead) && ++idx < info->philo_count)
			is_dead = check_alive(info, idx);
		if (is_dead)
		{
			print_died(&info->m_print, info->start_time, idx, DIE);
			break ;
		}
		if (info->must_eat && check_finish(info))
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
		pthread_mutex_init(&(info->m_forks[idx]), NULL);
		philos[idx].id = idx;
		philos[idx].info = info;
		if (pthread_create(&philos[idx].thread, NULL, \
			routine, (void *)(philos + idx)) != 0)
			break;
		idx++;
	}
	pthread_mutex_init(&(info->m_print), NULL);
	if (idx == info->philo_count)
		ft_manage(info);
	pthread_mutex_destroy(&(info->m_print));
	while (--idx >= 0)
	{
		pthread_mutex_destroy(&info->m_eat[idx]);
		pthread_mutex_destroy(&info->m_forks[idx]);
	}
}
