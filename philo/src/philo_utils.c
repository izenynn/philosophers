#include <philo.h>

size_t	get_time()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	hypnos(t_table *tab, size_t t_slp)
{
	size_t	t;

	i = get_time();
	while (!(tab->dead))
	{
		if (get_time() - t >= t_slp)
			break ;
	}
}
