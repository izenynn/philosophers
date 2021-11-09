/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:07:40 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/11/09 10:53:49 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/* print program usage */
static int	usage(void)
{
	write(STDERR_FILENO, "Error: invalid arguments (must be integers)\n", 44);
	write(STDERR_FILENO, "Usage: ./philo [N PHILOS] [DIE TIME] [EAT TIME]", 47);
	write(STDERR_FILENO, " [SLEEP TIME] (OPT)[PHILO EAT N TIMES]\n", 39);
	return (EXIT_FAILURE);
}

/* main */
int	main(int argc, char *argv[])
{
	int			i;
	t_table		tab;
	pthread_t	*tid;

	if ((argc < 5 || argc > 6) || handle_args(argc, argv, &tab))
		return (usage());
	tid = (pthread_t *)malloc(tab.n_philos * sizeof(pthread_t));
	tab.t_init = get_time();
	i = -1;
	while (++i < tab.n_philos)
	{
		if (pthread_create(&tid[i], NULL, &philo_life, &tab.philos[i]))
		{
			write(STDERR_FILENO, "Error: cannot create thread\n", 28);
			// TODO free();
			return(EXIT_FAILURE);
		}
		pthread_mutex_lock(&tab.check);
		tab.philos[i].last_eat = tab.t_init;
		pthread_mutex_unlock(&tab.check);
	}
	check_dead(&tab);
	exit_philo(&tab, tid);
	return (EXIT_SUCCESS);
}
