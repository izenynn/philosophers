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

	pthread_mutex_lock(&philo->chopstick);
	pthread_mutex_lock(&philo->r_philo->chopstick);

	printf("philo %d started\n", philo->id);
	usleep(10000000);
	printf("end!\n");

	pthread_mutex_unlock(&philo->chopstick);
	pthread_mutex_unlock(&philo->r_philo->chopstick);

	(void)philo;
	return (NULL);
}
