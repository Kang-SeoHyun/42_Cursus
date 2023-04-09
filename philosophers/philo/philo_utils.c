/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:18:09 by seokang           #+#    #+#             */
/*   Updated: 2023/04/04 16:15:26 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(pthread_mutex_t *m_print, size_t start, int idx, const char *message)
{
	pthread_mutex_lock(m_print);
	printf("%zu    %d %s\n", get_time(start), idx, message);
	pthread_mutex_unlock(m_print);
}

void	print_died(pthread_mutex_t *m_print, size_t start, int idx, const char *message)
{
	pthread_mutex_lock(m_print);
	printf("%zu    %d %s\n", get_time(start), idx, message);
	pthread_mutex_unlock(m_print);
	exit(1);
}

void	print_done(pthread_mutex_t *m_print)
{
	pthread_mutex_lock(m_print);
	printf("successfully!\n");
	pthread_mutex_unlock(m_print);
	exit(0);
}

size_t	get_time(size_t start) //get_milisecond
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - start);
}

void	smart_timer(int time) //msleep
{
	size_t	start;

	start = get_time(0);
	while (get_time(0) < time + start)
		usleep(100);
}
