/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:13:04 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/06 20:46:02 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *ph)
{
	gettime(ph);
	pthread_mutex_lock(ph->l_f);
	pthread_mutex_lock(ph->r_f);
	gettime(ph);
	pthread_mutex_lock(ph->lock);
	if (!*ph->is_ph_dead)
	{
		printf("%ld %d has taken\n", ph->start_time, ph->id);
		printf("%ld %d has taken\n", ph->start_time, ph->id);
	}
	pthread_mutex_unlock(ph->lock);
}

void	ft_think(t_philo *ph)
{
	gettime(ph);
	pthread_mutex_lock(ph->lock);
	if (!*ph->is_ph_dead)
		printf("%ld %d is thinking\n", ph->start_time, ph->id);
	pthread_mutex_unlock(ph->lock);
}

void	ft_sleep(t_philo *ph)
{
	gettime(ph);
	pthread_mutex_lock(ph->lock);
	if (!*ph->is_ph_dead)
		printf("%ld %d is sleeping\n", ph->start_time, ph->id);
	pthread_mutex_unlock(ph->lock);
	ft_usleep(ph, ph->time_to_eat);
}

void	eat(t_philo *ph)
{
	gettime(ph);
	pthread_mutex_lock(ph->lock);
	if (!*ph->is_ph_dead)
		printf("%ld %d is eating\n", ph->start_time, ph->id);
	pthread_mutex_unlock(ph->lock);
	ph->death = ph->start_time + ph->time_to_die;
	ph->hm_eat++;
	ft_usleep(ph, ph->time_to_eat);
	pthread_mutex_unlock(ph->r_f);
	pthread_mutex_unlock(ph->l_f);
}
