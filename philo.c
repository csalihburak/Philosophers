#include "philo.h"

void	ft_free(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->nbr_philo)
		pthread_mutex_destroy(&ph->fork[i++]);
	pthread_mutex_destroy(ph->lock);
	free(ph->fork);
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
	pthread_mutex_t *forks;
	int 			size;

	if (check_arg(ac, av) == 0 || ac > 6 || ac < 5)
		return (1);
	size = ft_atoi(av[1]);
	philo = malloc(sizeof(t_philo) * size);
	philo->all = philo;
	forks = init_mutex(size);
	set_forks(philo,forks, size);
	init_philosophers(philo, av, size);
/* 	for (int i = 0; i < size; i++)
		printf("%d r_f = [%p] l_f = [%p]\n", i, philo[i].r_f, philo[i].l_f);
	for (int i = 0; i < size; i++)
		printf("%p\n", &forks[i]); */
	create_threads(philo, ft_atoi(av[1]));
	join_threads(philo);
	ft_free(philo);
}

