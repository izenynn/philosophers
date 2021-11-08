/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 00:42:06 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/11/08 00:42:07 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

/* on exit */
void	exit_philo(t_table *tab)
{
	int	i;
	int	status;

	i = -1;
	while (++i < tab->n_philos)
	{
		waitpid(-1, &status, 0);
		if (status)
		{
			i = -1;
			while (++i < tab->n_philos)
				kill(tab->philos[i].pid, SIGKILL);
			break ;
		}
	}
	sem_close(tab->print);
	sem_close(tab->check);
	sem_close(tab->forks);
	sem_unlink("/p_print");
	sem_unlink("/p_check");
	sem_unlink("/p_forks");
	free(tab->philos);
}

/* get current time */
size_t	get_time(void)
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
