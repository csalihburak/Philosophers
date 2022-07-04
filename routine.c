#include "philo.h"

void	*routine(t_philo *philo)
{
	if(philo->nbr_philo == 1)
	{
		gettime(philo);
		printf("%ld %d has taken a fork\n", philo->start_time, philo->id);
		ft_usleep(philo, philo->time_to_die);
		printf("%ld %d is died\n", philo->start_time, philo->id);
		return (NULL);
	}
	while (1)
	{
		take_fork(philo);
		eat(philo);
		if(philo->hm_eat == philo->eat_keep)
			break ;
		ft_sleep(philo);

		ft_think(philo);
		usleep(200);
	}
	return (NULL);
}
