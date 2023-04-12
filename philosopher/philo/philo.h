/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:52:16 by seokang           #+#    #+#             */
/*   Updated: 2023/04/12 18:26:28 by seokang          ###   ########.fr       */
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

//color
# define RESET		"\033[0m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"

typedef struct s_status
{
	int	end;
	int	full;
}	t_status;

typedef struct s_arg
{
	int	philo_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
}	t_arg;

typedef struct s_info
{
	t_arg			arg;
	pthread_mutex_t	m_print;
	t_status		state;
	size_t			start_time;
}	t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	int				eat_cnt;
	size_t			last_eat_t;
	t_info			*info;
	pthread_mutex_t	*left_hand;
	pthread_mutex_t	*right_hand;
}	t_philo;

enum e_enum
{
	ERROR = -1,
	SUCCESS,
	EATTING
};

/* init */
int			init_info(t_philo **philo, t_info *info);

/* parsing */
int			parsing(t_info *info, int argc, char **argv);

/* print */
int			ft_error(char *str);
int			print_state(t_philo *philo, int idx, char *str, int eat_status);

/* philo_utils */
size_t		get_time(void);
void		msleep(int time);
void		monitor(t_philo *philo);
void		mutex_free(t_philo *philo, t_info *info, t_arg *arg);

void		*action(void *arg);

#endif
