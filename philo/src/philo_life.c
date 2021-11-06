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

void	*philo_life(void *arg)
{
	t_philo	*philo = (t_philo *)arg;

	if (philo->id % 2 == 0)
		usleep(10000);

	while (1)
	{
		if (philo->eat_cnt >= philo->table->tn_eat)
		{
			print_msg(philo, MSG_RIP);
			break ;
		}
		pthread_mutex_lock(&philo->fork);
		print_msg(philo, MSG_FORK);

		pthread_mutex_lock(&philo->r_philo->fork);
		print_msg(philo, MSG_FORK);

		usleep(500000);
		print_msg(philo, MSG_EAT);

		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->r_philo->fork);

		philo->eat_cnt++;

		/* sleep */
		print_msg(philo, MSG_SLP);
		usleep(philo->table->t_slp * 1000);

		/* think */
		print_msg(philo, MSG_THK);

	}

	(void)philo;
	return (NULL);
}
