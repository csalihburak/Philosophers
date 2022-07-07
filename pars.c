/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:07:37 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/07 16:56:25 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_forks(t_philo *philo, pthread_mutex_t *fork, int size)
{
	int	i;

	i = 0;
	if (size == 1)
	{
		philo[0].l_f = &fork[0];
	}
	else
	{
		while (i < size)
		{
			philo[i].l_f = &fork[i];
			philo[i].r_f = &fork[(i + 1) % size];
			i++;
		}
	}
	philo->fork = fork;
}

pthread_mutex_t	*init_mutex(int size)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * size);
	if (!fork)
		return (0);
	while (i < size)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	return (fork);
}

void	create_threads(t_philo *philo, int nbr_philo)
{
	int	i;

	i = 0;
	while (i < nbr_philo)
	{
		pthread_create(&philo[i].thread, NULL, \
			(void *)routine, &philo[i]);
		pthread_detach(philo[i].thread);
		i += 2;
	}
	i = 1;
	while (i < nbr_philo)
	{
		pthread_create(&philo[i].thread, NULL, \
			(void *)routine, &philo[i]);
		pthread_detach(philo[i].thread);
		i += 2;
	}
}

void	set_basics(t_philo *philo, char **av)
{
	int	i;
	int	size;

	i = 0;
	size = ft_atoi(av[1]);
	while (i < size)
	{
		philo[i].id = i + 1;
		philo[i].nbr_philo = size;
		philo[i].time_to_die = ft_atoi(av[2]);
		philo[i].time_to_eat = ft_atoi(av[3]);
		philo[i].time_to_sleep = ft_atoi(av[4]);
		philo[i].death = ft_atoi(av[2]);
		philo[i].eat_keep = -1;
		if (av[5])
			philo[i].eat_keep = ft_atoi(av[5]);
		i++;
	}
}

void	init_philosophers(t_philo *philo, char **av, int size)
{
	int				i;
	pthread_mutex_t	*lock;
	int				*dead;
	int				*full;

	i = 0;
	lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(lock, NULL);
	dead = malloc(sizeof(int));
	full = malloc(sizeof(int));
	*dead = 0;
	*full = 0;
	set_basics(philo, av);
	while (i < size)
	{
		philo[i].id = i + 1;
		philo[i].lock = lock;
		philo[i].is_full = full;
		philo[i].is_ph_dead = dead;
		philo[i].hm_eat = 0;
		philo[i].ms = 0;
		philo[i].start = 0;
		philo[i].start_time = 0;
		i++;
	}
}
