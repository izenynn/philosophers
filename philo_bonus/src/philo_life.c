/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:27:20 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/11/09 12:30:42 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

/* check for dead and if all meals eaten */
static void	*check_dead(void *arg)
{
	t_philo	*philo;
	t_table	*tab;

	philo = (t_philo *)arg;
	tab = philo->tab;
	while (1)
	{
		sem_wait(tab->check);
		if (get_time() - philo->last_eat > (size_t)tab->t_die)
		{
			print_msg(philo, MSG_RIP);
			sem_wait(tab->print);
			tab->dead = 1;
			exit (DEAD_EXIT);
		}
		sem_post(tab->check);
		if (tab->dead)
			break ;
		usleep(1000);
		if (tab->n_eat != -1 && philo->eat_cnt >= tab->n_eat)
			break ;
	}
	return (NULL);
}

/* take forks and eat */
static void	philo_eat(t_philo *philo)
{
	t_table	*tab;

	tab = philo->tab;
	sem_wait(philo->tab->forks);
	print_msg(philo, MSG_FORK);
	if (philo->tab->n_philos == 1)
	{
		hypnos(tab, tab->t_die);
		print_msg(philo, MSG_RIP);
		tab->dead = 1;
		return ;
	}
	sem_wait(philo->tab->forks);
	print_msg(philo, MSG_FORK);
	sem_wait(philo->tab->check);
	philo->eat_cnt++;
	print_msg(philo, MSG_EAT);
	philo->last_eat = get_time();
	sem_post(philo->tab->check);
	hypnos(tab, tab->t_eat);
	sem_post(philo->tab->forks);
	sem_post(philo->tab->forks);
}

/* philosophers life cicle */
void	*philo_life(void *arg)
{
	t_philo	*philo;
	t_table	*tab;

	philo = (t_philo *)arg;
	tab = philo->tab;
	philo->last_eat = tab->t_init;
	pthread_create(&philo->check_dead, NULL, check_dead, (void *)philo);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!tab->dead)
	{
		philo_eat(philo);
		if (tab->n_eat != -1 && philo->eat_cnt >= tab->n_eat)
			break ;
		print_msg(philo, MSG_SLP);
		hypnos(tab, tab->t_slp);
		print_msg(philo, MSG_THK);
	}
	pthread_join(philo->check_dead, NULL);
	exit (ALIVE_EXIT);
}
