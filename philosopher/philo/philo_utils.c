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

void	smart_timer(int time)
{
	size_t	start;

	start = get_time();
	while (get_time() < time + start)
		usleep(100);
}

void	monitor(t_philo *philo)
{
	int		i;
	int		end_f;
	size_t	now_t;

	while (1)
	{
		i = -1;
		while (++i < philo->info->arg.n_philo)
		{
			pthread_mutex_lock(&philo->info->mtx_print);
			end_f = philo->info->stat.end;
			now_t = get_time();
			if (now_t > philo->info->arg.die_time + philo[i].last_eat_t)
			{
				philo->info->stat.end++;
				printf(RED"%ld %d died\n"RESET, now_t - philo->info->birth_t, i + 1);
				pthread_mutex_unlock(&philo->info->mtx_print);
				return ;
			}
			else
				pthread_mutex_unlock(&philo->info->mtx_print);
			if (end_f)
				return ;
		}
	}
}

void	mutex_free(t_philo *philo, t_info *info, t_arg *arg)
{
	int	i;

	i = -1;
	while (++i < arg->n_philo)
		pthread_mutex_destroy(philo[i].mtx_left);
	pthread_mutex_destroy(&info->mtx_print);
	free(philo[0].mtx_left);
	free(philo);
}
