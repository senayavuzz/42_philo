#include "philo.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_atoi(argv[i]) == 0)
		{
			printf ("Wrong Arguments!");
			return (0);
		}
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf ("Wrong Arguments!");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_join_threads(t_philo *philo, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_create(&philo[i].thread, NULL, &dinner, &philo[i]);
		i++;
		usleep(1000);
	}
	while (*philo->is_dead != 1)
		end_control(philo);
}

int	main(int ac, char **av)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	if (ac != 5 && ac != 6)
		return (1);
	if (check_arg(ac, av) == 0)
		return (1);
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	death = malloc(sizeof(pthread_mutex_t));
	if (!philo && !forks && !death)
		return (1);
	init_philos(philo, ac, av);
	init_fork(philo, av, forks, death);
	ft_join_threads(philo, av);
	ft_free(philo, forks, death);
	return (0);
}
