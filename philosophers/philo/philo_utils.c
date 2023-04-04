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

size_t	get_time(void) //get_milisecond
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	smart_timer(int time) //msleep
{
	size_t	start;

	start = get_time();
	while (get_time() < time + start)
		usleep(100);
}

void	print_state(pthread_mutex_t *m_print, size_t start, int idx, const char *message)
{
	pthread_mutex_lock(m_print);
	printf("%lld\t%d %s\n", get_time(start), idx, message);
	pthread_mutex_unlock(m_print);
}

void	print_died(pthread_mutex_t *m_print, size_t start, int idx, const char *message)
{
	pthread_mutex_lock(m_print);
	printf("%lld\t%d %s\n", get_time(start), idx, message);
	exit(1); //실패
	pthread_mutex_unlock(m_print);
}

void	print_done(pthread_mutex_t *m_print)
{
	pthread_mutex_lock(m_print);
	printf("successfully!\n");
	exit(0); //성공
	pthread_mutex_unlock(m_print);
}
