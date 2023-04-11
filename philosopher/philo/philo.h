/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:52:16 by seokang           #+#    #+#             */
/*   Updated: 2023/04/11 22:41:24 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# define VAL_INT_MAX			2147483647
# define VAL_INT_MIN			2147483648

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
	int	n_full;
}	t_status;

typedef struct s_arg
{
	int	n_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	must_eat;
}	t_arg;

typedef struct s_info
{
	t_arg			arg;
	pthread_mutex_t	mtx_print;
	t_status		stat;
	size_t			birth_t;
}	t_info;

typedef struct s_philo
{
	int				idx;
	pthread_t		tid;
	int				cnt_eat;
	size_t			last_eat_t;
	t_info			*info;
	pthread_mutex_t	*mtx_left;
	pthread_mutex_t	*mtx_right;
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
int			parsing(int argc, char **argv, t_info *info);

/* print */
int			ft_error(char *str);
int			print_state(t_philo *philo, int idx, char *str, int eat_status);

/* philo_utils */
size_t		get_time(void);
void		smart_timer(int time);
void		monitor(t_philo *philo);
void		mutex_free(t_philo *philo, t_info *info, t_arg *arg);

void		*action(void *param);

#endif
