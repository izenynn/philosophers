/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:07:40 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/11/08 17:30:18 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

/* print program usage */
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
	int			i;
	t_table		tab;

	if ((argc < 5 || argc > 6) || handle_args(argc, argv, &tab))
		usage();
	tab.t_init = get_time();
	i = -1;
	while (++i < tab.n_philos)
	{
		tab.philos[i].pid = fork();
		if (tab.philos[i].pid == -1)
		{
			write(STDERR_FILENO, "Error: fork failed\n", 19);
			exit(EXIT_FAILURE);
		}
		/* child procces */
		if (tab.philos[i].pid == 0)
			philo_life((void *)&tab.philos[i]);
		//tab.philos[i].last_eat = tab.t_init;
		usleep(100); // ?
	}
	//check_dead(&tab);
	exit_philo(&tab);
	return (EXIT_SUCCESS);
}
