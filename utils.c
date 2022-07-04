/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:13:10 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/04 13:16:07 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] < '0' || arr[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg *= -1;
	if ((str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * neg);
}

void	gettime(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	gettimeofday(&philo->tv, NULL);
	philo->ms = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	if (philo->start == 0)
		philo->start = philo->ms;
	philo->start_time = (philo->ms) - (philo->start);
	pthread_mutex_unlock(philo->lock);
}

int	ft_usleep(t_philo *ph, long ms)
{
	long	time;

	gettime(ph);
	time = ph->start_time;
	while (ph->start_time < ms + time)
	{
		gettime(ph);
	}
	return (1);
}
