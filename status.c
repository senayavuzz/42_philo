#include "philo.h"

int	dead_control(t_philo *philo, int i, t_time time)
{
	if ((int)time > philo[i].time_to_die)
	{
		printf("%llu %d %s\n", time, philo[i].id + 1, "died");
		*philo->is_dead = 1;
		return (1);
	}
	return (0);
}

int	dinner_control(t_philo *philo, int *philos, int *total_eat)
{
	if (philo->must_eat != -1)
	{
		while (*philos < philo->nbr_philo)
			*total_eat += philo[(*philos)++].meals_eaten;
		if (*total_eat >= philo->nbr_philo * philo->must_eat)
		{
			*philo->is_dead = 1;
			return (1);
		}
	}
	return (0);
}

void	end_control(t_philo *philo)
{
	t_time	time;
	int		i;
	int		index;
	int		total_eat;

	i = 0;
	index = 0;
	total_eat = 0;
	while (i < philo->nbr_philo)
	{
		pthread_mutex_lock(philo->death);
		time = get_ms() - philo[i].last_meal;
		if (dead_control(philo, i, time)
			|| dinner_control(philo, &index, &total_eat))
			break ;
		i++;
		pthread_mutex_unlock(philo->death);
	}
}

void	status(t_philo *philo, char *status)
{
	t_time	time;

	time = get_ms() - philo->start_time;
	pthread_mutex_lock(philo->death);
	if (*philo->is_dead == 0)
		printf("%llu %d %s\n", time, philo->id + 1, status);
	pthread_mutex_unlock(philo->death);
}
