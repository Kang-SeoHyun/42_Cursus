/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:54:27 by seokang           #+#    #+#             */
/*   Updated: 2023/04/12 18:29:37 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_info *info, pthread_mutex_t **fork)
{
	int	i;

	if (pthread_mutex_init(&info->m_print, NULL) != 0)
		return (ERROR);
	*fork = malloc(sizeof(pthread_mutex_t) * info->arg.philo_count);
	if (!(*fork))
		return (ERROR);
	i = -1;
	while (++i < info->arg.philo_count)
		if (pthread_mutex_init(&(*fork)[i], NULL) != 0)
			return (ERROR);
	return (SUCCESS);
}

static int	init_philo(t_philo **philo, t_info *info, t_arg *arg, pthread_mutex_t *fork)
{
	int	i;

	(*philo) = malloc(sizeof(t_philo) * arg->philo_count);
	if (!philo)
		return (ERROR);
	i = -1;
	while (++i < arg->philo_count)
	{
		(*philo)[i].id = i;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].info = info;
		(*philo)[i].left_hand = &fork[i];
		(*philo)[i].right_hand = &fork[(i + 1) % (arg->philo_count)];
		(*philo)[i].last_eat_t = get_time();
	}
	pthread_mutex_lock(&info->m_print);
	i = -1;
	while (++i < arg->philo_count)
		if (pthread_create(&(*philo)[i].tid, NULL, action, &(*philo)[i]))
			return (ft_error("pthread_create is not working."));
	info->start_time = get_time();
	pthread_mutex_unlock(&info->m_print);
	return (SUCCESS);
}

int	init_info(t_philo **philo, t_info *info)
{
	pthread_mutex_t	*fork;

	info->state.end = 0;
	info->state.full = 0;
	if (init_mutex(info, &fork) == ERROR)
		return (ft_error("init_mutex is not working."));
	if (init_philo(philo, info, &info->arg, fork) == ERROR)
		return (ft_error("init_philo is not working."));
	return (SUCCESS);
}
