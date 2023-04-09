/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:18:06 by seokang           #+#    #+#             */
/*   Updated: 2023/04/08 18:20:07 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	pickup(t_philo *philo)
{

}

static void	eat(t_philo *philo)
{

}

static void	putdown(t_philo *philo)
{

}

void    *routine(void *arg)
{
    t_philo *philo;
    t_info  *info;

    philo = (t_philo *)arg;
    info = philo->info;
    while (info->start_time == 0)
        smart_timer(10);
    while (1)
    {
        /*
        포크들고
        먹고 
        내려놓고
        자는거 프린트하고
        smart timer
        생각하는거 프린트하고
        */
    }
}
