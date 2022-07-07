/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:12:51 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/07 17:27:13 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	deadcheck(t_philo *ph)
{
	while (1 && ph->nbr_philo != 1)
	{
		pthread_mutex_lock(ph->lock);
		if (*ph->is_ph_dead)
			return ;
		pthread_mutex_unlock(ph->lock);
	}
}

void	ft_free(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->nbr_philo)
		pthread_mutex_destroy(&ph->fork[i++]);
	pthread_mutex_destroy(ph->lock);
	free(ph->fork);
	free(ph->lock);
	free(ph->is_ph_dead);
	free(ph->is_full);
	free(ph);
}

int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Wrong argument number!\n");
		return (0);
	}
	while (av[i])
	{
		if (is_digit(av[i]) == 0 || ft_atoi(av[i]) <= 0)
		{
			printf("Wrong argument!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				size;

	if (check_arg(ac, av) == 0 || ac > 6 || ac < 5)
		return (1);
	size = ft_atoi(av[1]);
	philo = malloc(sizeof(t_philo) * size);
	philo->all = philo;
	forks = init_mutex(size);
	set_forks(philo, forks, size);
	init_philosophers(philo, av, size);
	create_threads(philo, ft_atoi(av[1]));
	if (size == 1)
		usleep(philo->time_to_die * 1000);
	deadcheck(philo);
	ft_free(philo);
	return (0);
}
