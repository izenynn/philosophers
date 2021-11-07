#include <philo.h>

/* on exit */
void	exit_philo(t_table *tab, pthread_t *tid)
{
	int	i;

	i = -1;
	while (++i < tab->n_philos)
		pthread_join(tid[i], NULL);
	i = -1;
	while (++i < tab->n_philos)
		pthread_mutex_destroy(&tab->philos[i].fork);
	pthread_mutex_destroy(&tab->print);
	free(tab->philos);
	free(tid);
}

/* get current time */
size_t	get_time()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

/* custom usleep function */
void	hypnos(t_table *tab, size_t t_slp)
{
	size_t	t;

	t = get_time();
	while (!(tab->dead))
	{
		if (get_time() - t >= t_slp)
			break ;
		usleep(10);
	}
}

