#include "philo.h"

void	go_kill(t_philo *ph)
{
	pthread_mutex_lock(ph->lock);
	if (*ph->is_ph_dead)
	{
		gettime(ph);
		*ph->is_ph_dead = 0;
		printf("%ld %d is died\n", ph->death, ph->id);
		pthread_mutex_unlock(ph->l_f);
		pthread_mutex_unlock(ph->r_f);
	}
	pthread_mutex_unlock(ph->lock);
}

int	is_good(t_philo *ph)
{
	int val;

	pthread_mutex_lock(ph->lock);
	val = *ph->is_ph_dead;
	pthread_mutex_unlock(ph->lock);
	return (val);
}

void	deadcheck(t_philo *ph)
{
	gettime(ph);
	if (ph->start_time > ph->death)
		go_kill(ph);
}

void	*routine(t_philo *philo)
{
	if(philo->nbr_philo == 1)
	{
		gettime(philo);
		printf("%ld %d has taken a fork\n", philo->start_time, philo->id);
		ft_usleep(philo, philo->time_to_die);
		printf("%ld %d is diead\n", philo->start_time, philo->id);
		return (NULL);
	}
	while (1)
	{
/* 		take_fork(philo);
		if (!is_good(philo))
			return (NULL);
		eat(philo);
		if (!is_good(philo))
			return (NULL);
		deadcheck(philo);
		if(philo->hm_eat == philo->eat_keep)
			break ;
		ft_sleep(philo);

		ft_think(philo);
		usleep(200); */
		if(take_fork(philo))
			return (NULL);
		if(eat(philo))
			return (NULL);
		if(philo->hm_eat == philo->eat_keep)
			break;
		if (!is_good(philo))
			return (NULL);
		if(ft_sleep(philo))
			return (NULL);
		if (!is_good(philo))
			return (NULL);
		if(ft_think(philo))
			return (NULL);
		if (!is_good(philo))
			return (NULL);	
	}
	return (NULL);
}
