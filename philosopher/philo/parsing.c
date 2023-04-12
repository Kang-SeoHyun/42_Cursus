/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:29:19 by seokang           #+#    #+#             */
/*   Updated: 2023/04/12 19:00:32 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str == '\0')
		return (num);
	else
		return (-1);
}

int	parsing(t_info *info, int argc, char **argv)
{
	info->arg.philo_count = ft_atoi(argv[1]);
	if (info->arg.philo_count <= 0)
		return (ft_error("There's no philosopher."));
	info->arg.time_to_die = ft_atoi(argv[2]);
	info->arg.time_to_eat = ft_atoi(argv[3]);
	info->arg.time_to_sleep = ft_atoi(argv[4]);
	if (info->arg.time_to_die <= 0 || info->arg.time_to_eat <= 0
		|| info->arg.time_to_sleep <= 0)
		return (ft_error("The time is weird."));
	info->arg.must_eat = 0;
	if (argc == 6)
	{
		info->arg.must_eat = ft_atoi(argv[5]);
		if (info->arg.must_eat <= 0)
			return (ft_error("The number of must_eat is weird."));
	}
	return (SUCCESS);
}
