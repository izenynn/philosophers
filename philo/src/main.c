/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:07:40 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/11/04 10:07:57 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	usage(void)
{
	write(STDERR_FILENO, "Error: invalid arguments (must be integers)\n", 44);
	write(STDERR_FILENO, "Usage: ./philo [N PHILOS] [DIE TIME] [EAT TIME]", 47);
	write(STDERR_FILENO, " [SLEEP TIME] (OPT)[PHILO EAT N TIMES]\n", 39);
	exit(EXIT_FAILURE);
}

/* main */
int	main(int argc, char *argv[])
{
	t_table		tab;
	pthread_t	*tid;

	if ((argc < 5 || argc > 6) || handle_args(argc, argv, &tab))
		usage();
	tid = (pthread_t *)malloc(tab.n_philos * sizeof(pthread_t));
	/* get init time */
	tab.t_init = get_time();
	/* create threads */
	for (int i = 0; i < tab.n_philos; i++) {
		pthread_create(&tid[i], NULL, &philo_life, &tab.philos[i]);
		/* set last eat time to init */
		tab.philos[i].last_eat = tab.t_init;
	}
	/*for (int i = 0; i < tab.n_philos; i++) {
		pthread_join(tid[i], NULL);
	}*/
	//
	// TODO mutex destroy... ?
	check_dead(&tab);
	exit_philo(&tab, tid);
	return (EXIT_SUCCESS);
}
