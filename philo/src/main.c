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

int	main(int argc, char *argv[])
{
	t_table	tab;

	if ((argc < 5 || argc > 6) || handle_args(argc, argv, &tab))
		usage();
	// TEST CODE
	printf("nphilos: %d\n", tab.n_philo);
	for (int i = 0; i < tab.n_philo; i++)
		print_msg(&tab.philos[i], MSG_RIP);
	//
	free(tab.philos);
	return (EXIT_SUCCESS);
}
