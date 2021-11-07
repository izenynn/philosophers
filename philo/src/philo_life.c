/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:27:20 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/11/04 17:27:21 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	check_dead(t_table *tab)
{
	int	i;

	while (!tab->eaten_all)
	{
		i = -1;
		while (!tab->dead && ++i < tab->n_philos)
		{
			if (get_time() - tab->philos[i].last_eat > (size_t)tab->t_die)
			{
				print_msg(&tab->philos[i], MSG_RIP);
				tab->dead = 1;
			}
			/* wait a little to make sure msgs are printed */
			usleep(100);
		}
		if (tab->dead)
			break ;
		i = 0;
		while (tab->n_eat != -1 && i < tab->n_philos
			&& tab->philos[i].eat_cnt >= tab->n_eat)
			i++;
		if (i == tab->n_philos)
			tab->eaten_all = 1;
	}
}

static void	philo_eat(t_philo *philo)
{
	t_table	*tab;

	tab = philo->tab;
	/* take fork #1 */
	pthread_mutex_lock(&philo->fork);
	print_msg(philo, MSG_FORK);
	/* take fork #2 */
	pthread_mutex_lock(&philo->r_philo->fork);
	print_msg(philo, MSG_FORK);
	/* eat */
	print_msg(philo, MSG_EAT);
	/* update last eat */
	philo->last_eat = get_time();
	/* eating... */
	hypnos(tab, tab->t_eat);
	/* update total eats */
	philo->eat_cnt++;
	/* release fork */
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->r_philo->fork);
}

void	*philo_life(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	t_table	*tab = philo->tab;

	/* prevent all philosophers of taking a fork */
	if (philo->id % 2 == 0)
		usleep(100);

	/* philosophers life cicle \(^^)/ */
	while (!tab->dead)
	{
		/* eat */
		philo_eat(philo);
		/* check if all have ate n meals */
		if (tab->eaten_all)
			break ;
		/* sleep */
		print_msg(philo, MSG_SLP);
		hypnos(tab, tab->t_slp);

		/* think */
		print_msg(philo, MSG_THK);

	}

	return (NULL);
}
