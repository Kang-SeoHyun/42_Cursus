/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:55:12 by seokang           #+#    #+#             */
/*   Updated: 2023/04/12 18:31:59 by seokang          ###   ########.fr       */
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
	size_t	now_time;

	pthread_mutex_lock(&philo->info->m_print);
	if (philo->info->state.end == 0)
	{
		now_time = get_time();
		printf("%ld %d %s\n", now_time - philo->info->start_time, idx + 1, str);
		if (eat_status)
		{
			philo->last_eat_t = now_time;
			if (++(philo->eat_cnt) == philo->info->arg.must_eat)
			{
				philo->info->state.full++;
				if (philo->info->state.full == philo->info->arg.philo_count)
					philo->info->state.end++;
			}
		}
	}
	else
	{
		pthread_mutex_unlock(&philo->info->m_print);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->info->m_print);
	return (SUCCESS);
}
