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
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"

typedef struct s_status
{
	int	end;
	int	n_full;
}		t_status;

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
	t_status	status;
	pthread_t	thread;

}				t_philo;

#endif
