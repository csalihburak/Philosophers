/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:13:04 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/05 14:36:19 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *ph)
{
	gettime(ph);
	pthread_mutex_lock(ph->l_f);
	pthread_mutex_lock(ph->r_f);
	gettime(ph);
	printf("\033[31m%ld %d has taken lfork [%p]\n", ph->start_time, \
	ph->id, ph->l_f);
	printf("\033[31m%ld %d has taken rfork [%p]\n", ph->start_time, \
	ph->id, ph->r_f);
}

void	ft_think(t_philo *ph)
{
	gettime(ph);
	printf("\033[36m%ld %d is thinking\n", ph->start_time, ph->id);
}

void	ft_sleep(t_philo *ph)
{
	gettime(ph);
	printf("\033[37m%ld %d is sleeping\n", ph->start_time, ph->id);
	ft_usleep(ph, ph->time_to_eat);
}

void	eat(t_philo *ph)
{
	gettime(ph);
	printf("\033[33m%ld %d is eating\n", ph->start_time, ph->id);
	ph->death = ph->start_time + ph->time_to_die;
	ft_usleep(ph, ph->time_to_eat);
	ph->hm_eat++;
	pthread_mutex_unlock(ph->r_f);
	pthread_mutex_unlock(ph->l_f);
	usleep(300);
}
