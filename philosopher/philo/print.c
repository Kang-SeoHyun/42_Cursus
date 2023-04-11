/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:55:12 by seokang           #+#    #+#             */
/*   Updated: 2023/04/11 22:37:23 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	printf(RED"ERROR : %s\n"RESET, str);
	return (ERROR);
}

int	print_state(t_philo *philo, int idx, char *str, int eat_status)
{
	size_t	now_t;

	pthread_mutex_lock(&philo->info->mtx_print);
	if (philo->info->stat.end == 0)
	{
		now_t = get_time();
		printf("%ld %d %s\n", now_t - philo->info->birth_t, idx + 1, str);
		if (eat_status)
		{
			philo->last_eat_t = now_t;
			if (++(philo->cnt_eat) == philo->info->arg.must_eat)
			{
				philo->info->stat.n_full++;
				if (philo->info->stat.n_full == philo->info->arg.n_philo)
					philo->info->stat.end++;
			}
		}
	}
	else
	{
		pthread_mutex_unlock(&philo->info->mtx_print);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->info->mtx_print);
	return (SUCCESS);
}
