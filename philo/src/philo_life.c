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

	pthread_mutex_lock(&philo->chopstick);
	pthread_mutex_lock(&philo->r_philo->chopstick);

	print_msg(philo, MSG_FORK);
	usleep(500000);
	print_msg(philo, MSG_RIP);

	pthread_mutex_unlock(&philo->chopstick);
	pthread_mutex_unlock(&philo->r_philo->chopstick);

	(void)philo;
	return (NULL);
}
