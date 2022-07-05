/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:13:04 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/05 18:33:17 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *ph)
{
	gettime(ph);
	pthread_mutex_lock(ph->l_f);
	pthread_mutex_lock(ph->r_f);
	gettime(ph);
	printf("%ld %d has taken\n", ph->start_time, ph->id);
	printf("%ld %d has taken\n", ph->start_time, ph->id);
}

void	ft_think(t_philo *ph)
{
	gettime(ph);
	usleep(100);
	printf("%ld %d is thinking\n", ph->start_time, ph->id);
}

void	ft_sleep(t_philo *ph)
{
	gettime(ph);
	printf("%ld %d is sleeping\n", ph->start_time, ph->id);
	ft_usleep(ph, ph->time_to_eat);
}

void	eat(t_philo *ph)
{
	gettime(ph);
	printf("%ld %d is eating\n", ph->start_time, ph->id);
	ph->death = ph->start_time + ph->time_to_die;
	ph->hm_eat++;
	ft_usleep(ph, ph->time_to_eat);
	pthread_mutex_unlock(ph->r_f);
	pthread_mutex_unlock(ph->l_f);
}
