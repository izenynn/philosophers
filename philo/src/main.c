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

void	usage()
{
	write(STDERR_FILENO, "Error: invalid arguments\n", 25);
	write(STDERR_FILENO, "Usage: ./philo [N PHILO] [DIE TIME] [EAT TIME]", 46);
	write(STDERR_FILENO, " [SLEEP TIME] (opt)[PHILO EAT N TIMES]\n", 39);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_table tab;

	if ((argc < 5 || argc > 6) || handle_args(argc, argv, &tab))
		usage();
	free(tab.philos);
	return (EXIT_SUCCESS);
}
