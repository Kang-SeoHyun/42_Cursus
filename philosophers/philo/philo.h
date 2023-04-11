/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:18:12 by seokang           #+#    #+#             */
/*   Updated: 2023/04/11 18:13:05 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

//flag
# define PICKUP		"has taken a fork"
# define EAT		"is eating"
# define SLEEP		"is sleeping"
# define THINK		"is thinking"
# define DIE		"died"

# define MAX_PHILO 200
//color
# define RESET		"\033[0m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"

typedef struct s_info
{
	int				philo_count;
	size_t			start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				eat_cnt[MAX_PHILO];
	size_t			last_eat_time[MAX_PHILO];
	pthread_mutex_t	m_eat[MAX_PHILO];
	pthread_mutex_t	m_forks[MAX_PHILO];
	pthread_mutex_t	m_print;
}					t_info;

typedef struct s_philo
{
	int			id;
	t_info 		*info;
	pthread_t	thread;
}				t_philo;

/* main */
int	ft_error(char *str);

/* parsing */
int		parsing(t_info	*info, int argc, char *argv[]);

/* utils */
void	print_state(pthread_mutex_t *m_print, size_t start, int idx, const char *message);
void	print_died(pthread_mutex_t *m_print, size_t start, int idx, const char *message);
void	print_done(pthread_mutex_t *m_print);
size_t	get_time(size_t start);
void	smart_timer(size_t time);

/* simulate */
void	simulate(t_info *info);

/* philosopher */
void    *routine(void *arg);

#endif
