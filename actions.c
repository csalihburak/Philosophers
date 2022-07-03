#include "philo.h"

int	take_fork(t_philo *ph)
{
	deadcheck(ph);
	if (is_good(ph))
	{
		gettime(ph);
		pthread_mutex_lock(ph->l_f);
		pthread_mutex_lock(ph->r_f);
		gettime(ph);
		if(is_good(ph))
		{
			printf("\033[31m%ld %d has taken lfork [%p]\n", ph->start_time, ph->id, ph->l_f);
			printf("\033[31m%ld %d has taken rfork [%p]\n", ph->start_time, ph->id, ph->r_f);
		}
	}
	else
		return(1);
	return (0);
}

int	ft_think(t_philo *ph)
{
	deadcheck(ph);
	if (is_good(ph))
	{
		gettime(ph);
		printf("\033[36m%ld %d is thinking\n",ph->start_time, ph->id);
	}
	else
		return (1);
	return (0);
}

int	ft_sleep(t_philo *ph)
{
	deadcheck(ph);
	if (is_good(ph))
	{
		gettime(ph);
		printf("\033[37m%ld %d is sleeping\n", ph->start_time, ph->id);
		if (!ft_usleep(ph, ph->time_to_eat))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	eat(t_philo *ph)
{
	deadcheck(ph);
	if (is_good(ph))
	{
		gettime(ph);
		printf("\033[33m%ld %d is eating\n", ph->start_time, ph->id);
		ph->death = ph->start_time + ph->time_to_die;
		if (!ft_usleep(ph, ph->time_to_eat))
			return (1);
		ph->hm_eat++;
		pthread_mutex_unlock(ph->r_f);
		pthread_mutex_unlock(ph->l_f);
	}
	else
		return (1);
	return(0);
}
