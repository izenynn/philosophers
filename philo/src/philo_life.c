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

void	philo_eat(t_philo *philo)
{
	t_table	*tab;

	tab = philo->tab;
	/* take forks */
	pthread_mutex_lock(&philo->fork);
	print_msg(philo, MSG_FORK);
	pthread_mutex_lock(&philo->r_philo->fork);
	print_msg(philo, MSG_FORK);
	/* eat */
	print_msg(philo, MSG_EAT);
	/* update last eat */
	philo->last_eat = get_time();
	/* eating... */
	hypnos();
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

	if (philo->id % 2 == 0)
		usleep(10000);

	while (!tab->dead)
	{
		/* eat */
		philo_eat(philo);
		/* check if all have ate n meals */
		if (tab->eat_cnt_all)
			break ;
		/* sleep */
		print_msg(philo, MSG_SLP);
		usleep(philo->tab->t_slp * 1000);

		/* think */
		print_msg(philo, MSG_THK);

	}

	(void)philo;
	return (NULL);
}
