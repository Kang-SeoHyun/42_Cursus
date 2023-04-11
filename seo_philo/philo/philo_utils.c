/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:18:09 by seokang           #+#    #+#             */
/*   Updated: 2023/04/11 21:41:07 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_info *info, int idx, const char *message)
{
	pthread_mutex_lock(&info->m_print);
	if (info->end)
	{
		pthread_mutex_unlock(&info->m_print);
		return ;
	}
	printf("%zu    %d %s\n", get_time(info->start_time), idx, message);
	pthread_mutex_unlock(&info->m_print);
}

void	print_died(pthread_mutex_t *m_print, size_t start, int idx, const char *message)
{
	pthread_mutex_lock(m_print);
	printf(RED"%zu    %d %s\n"RESET, get_time(start), idx, message);
	pthread_mutex_unlock(m_print);
}

void	print_done(pthread_mutex_t *m_print)
{
	pthread_mutex_lock(m_print);
	printf(GREEN"It's a success!\n"RESET);
	pthread_mutex_unlock(m_print);
}

size_t	get_time(size_t start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - start);
}

void	smart_timer(size_t time)
{
	size_t	start;

	start = get_time(0);
	while (get_time(0) < time + start)
		usleep(100);
}
