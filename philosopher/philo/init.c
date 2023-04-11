/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:54:27 by seokang           #+#    #+#             */
/*   Updated: 2023/04/11 22:34:47 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_info *info, pthread_mutex_t **fork)
{
	int	i;

	*fork = malloc(sizeof(pthread_mutex_t) * info->arg.n_philo);
	if (!(*fork))
		return (ERROR);
	i = -1;
	while (++i < info->arg.n_philo)
		if (pthread_mutex_init(&(*fork)[i], PTHREAD_MUTEX_NORMAL) != 0)
			return (ERROR);
	if (pthread_mutex_init(&info->mtx_print, PTHREAD_MUTEX_NORMAL) != 0)
		return (ERROR);
	return (SUCCESS);
}

static int	init_philo(t_philo **philo, t_info *info, t_arg *arg, pthread_mutex_t *fork)
{
	int	i;

	(*philo) = malloc(sizeof(t_philo) * arg->n_philo);
	if (*philo == NULL)
		return (ERROR);
	i = -1;
	while (++i < arg->n_philo)
	{
		(*philo)[i].idx = i;
		(*philo)[i].cnt_eat = 0;
		(*philo)[i].info = info;
		(*philo)[i].mtx_left = &fork[i];
		(*philo)[i].mtx_right = &fork[(i + 1) % arg->n_philo];
		(*philo)[i].last_eat_t = get_time();
	}
	pthread_mutex_lock(&info->mtx_print);
	i = -1;
	while (++i < arg->n_philo)
		if (pthread_create(&(*philo)[i].tid, NULL, action, &(*philo)[i]))
			return (ft_error("pthread_create is not working."));
	info->birth_t = get_time();
	pthread_mutex_unlock(&info->mtx_print);
	return (SUCCESS);
}

int	init_info(t_philo **philo, t_info *info)
{
	pthread_mutex_t	*fork;

	info->stat.end = 0;
	info->stat.n_full = 0;
	if (init_mutex(info, &fork) == ERROR)
		return (ft_error("init_mutex is not working."));
	if (init_philo(philo, info, &info->arg, fork) == ERROR)
		return (ft_error("init_philo is not working."));
	return (SUCCESS);
}
