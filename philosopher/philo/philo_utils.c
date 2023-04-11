/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:53:52 by seokang           #+#    #+#             */
/*   Updated: 2023/04/11 22:54:45 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	msleep(int time)
{
	size_t	start;

	start = get_time();
	while (get_time() < time + start)
		usleep(100);
}

void	monitor(t_philo *philo)
{
	int		i;
	int		is_end;
	size_t	now_time;

	while (1)
	{
		i = -1;
		while (++i < philo->info->arg.philo_count)
		{
			pthread_mutex_lock(&philo->info->m_print);
			is_end = philo->info->state.end;
			now_time = get_time();
			if (now_time > philo->info->arg.time_to_die + philo[i].last_eat_t)
			{
				philo->info->state.end++;
				printf(RED"%ld %d died\n"RESET, (now_time - philo->info->start_time), i + 1);
				pthread_mutex_unlock(&philo->info->m_print);
				return ;
			}
			else
				pthread_mutex_unlock(&philo->info->m_print);
			if (is_end)
				return ;
		}
	}
}

void	mutex_free(t_philo *philo, t_info *info, t_arg *arg)
{
	int	i;

	i = -1;
	while (++i < arg->philo_count)
		pthread_mutex_destroy(philo[i].left_hand);
	pthread_mutex_destroy(&info->m_print);
	free(philo[0].left_hand);
	free(philo);
}
