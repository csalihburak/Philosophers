/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:12:51 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/05 14:34:09 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	deadcheck(t_philo *ph)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (1 && (ph->nbr_philo != 1))
	{
		i = -1;
		while (++i < ph->nbr_philo)
		{
			gettime(&ph[i]);
			if (ph[i].start_time > ph[i].death)
			{
				printf("%ld %d is died\n", ph->death, ph->id);
				return ;
			}
			if (ph[i].hm_eat == ph[i].eat_keep)
				count++;
			if (count == ph->nbr_philo)
				return ;
		}
		count = 0;
	}
}

void	ft_free(t_philo *ph)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(ph->lock);
	free(ph->fork);
	free(ph->lock);
	free(ph);
	//system("leaks philo");
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
		pthread_join(philo[0].thread, NULL);
	//join_thread(philo);
	deadcheck(philo);
	ft_free(philo);
	return (0);
}
