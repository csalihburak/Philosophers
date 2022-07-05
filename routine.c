/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:13:13 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/05 18:25:56 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_kill(t_philo *ph)
{
	pthread_mutex_lock(ph->lock);
	printf("%ld %d is died\n", ph->start_time, ph->id);
	*ph->is_ph_dead = 1;
	pthread_mutex_unlock(ph->lock);
}

void	*routine(t_philo *philo)
{
	if (philo->nbr_philo == 1)
	{
		gettime(philo);
		printf("%ld %d has taken a fork\n", philo->start_time, philo->id);
		ft_usleep(philo, philo->time_to_die);
		printf("%ld %d is died\n", philo->start_time, philo->id);
		*philo->is_ph_dead = 1;
		return (NULL);
	}
	while (1)
	{
		take_fork(philo);
		eat(philo);
		if (philo->hm_eat == philo->eat_keep)
			break ;
		ft_sleep(philo);
		ft_think(philo);
		usleep(200);
	}
	return (NULL);
}
