/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:54:46 by seokang           #+#    #+#             */
/*   Updated: 2023/04/11 22:46:00 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;
	t_philo	*philo;

	if (parsing(argc, argv, &info) == ERROR)
		return (ERROR);
	if (init_info(&philo, &info) == SUCCESS)
		monitor(philo);
	i = -1;
	while (++i < philo->info->arg.n_philo)
		pthread_mutex_unlock(philo[i].mtx_left);
	i = -1;
	while (++i < philo->info->arg.n_philo)
		pthread_join(philo[i].tid, NULL);
	mutex_free(philo, philo->info, &philo->info->arg);
	printf(GREEN"It's a success!\n"RESET);
	return (0);
}
