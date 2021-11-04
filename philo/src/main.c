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
	printf("Error: invalid arguments\n");
	printf("Usage: ./philo [N PHILO] [DIE TIME] [EAT TIME] [SLEEP TIME] (opt)[PHILO EAT N TIMES]\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		usage();
	for (int i = 0; i < argc; i++)
		printf("arg %2d: %s\n", i, argv[i]);
	return (EXIT_SUCCESS);
}
