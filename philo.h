#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

typedef struct s_philo
{
	int				id;
	int				nbr_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	long			last_meal;
	long			death;
	int				hm_eat;
	int				is_full;
	int				*is_ph_dead;
	int				eat_keep;
	struct timeval	tv;
	long			ms;
	long			start;
	struct s_philo	*all;
	pthread_t		thread;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*l_f;
	pthread_mutex_t	*r_f;
}	t_philo;

pthread_mutex_t	*init_mutex(int size);
int				is_digit(char *arr);
int				meal_check(t_philo *philo);
int				ft_usleep(t_philo *ph, long ms);
int				is_good(t_philo *ph);
long			ft_atoi(const char *str);
void			gettime(t_philo *philo);
void			set_forks(t_philo *philo, pthread_mutex_t *fork, int size);
void			init_philosophers(t_philo *philo, char **av, int size);
void			create_threads(t_philo *philo, int nbr_philo);
void			join_threads(t_philo *ph);
void			*routine(t_philo *philo);
void			deadcheck(t_philo *ph);
void			eat(t_philo *ph);
void			take_fork(t_philo *ph);
void			ft_think(t_philo *ph);
void			ft_sleep(t_philo *ph);

#endif
