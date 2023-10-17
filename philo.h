#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				id;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				meals_eaten;
	int				*is_dead;
	pthread_mutex_t	*death;
	t_time			last_meal;
	t_time			start_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philo;

int		dining(t_philo *philo);
void	*dinner(void *args);

void	init_philos(t_philo *philo, int argc, char **argv);
void	init_fork(t_philo *philo, char **argv,
			pthread_mutex_t *forks, pthread_mutex_t *death);

int		check_arg(int argc, char **argv);
void	ft_join_threads(t_philo *philo, char **argv);

void	status(t_philo *philo, char *status);
void	end_control(t_philo *philo);
int		dinner_control(t_philo *philo, int *philos, int *total_eat);
int		dead_control(t_philo *philo, int i, t_time time);

long	ft_atoi(const char *str);
t_time	get_ms(void);
void	ft_sleep(int wait_time);
void	ft_free(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death);

#endif
