/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:06:52 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/11/04 10:06:53 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* philo struct */
typedef struct s_philo
{
	size_t	test;
}	t_philo;

/* philo table struct */
typedef struct s_table
{
	int		t_die;
	int		t_eat;
	int		t_slp;
	int		tn_eat;
	int		n_philo;
	t_philo	*philos;
}	t_table;

/* utils.c */
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);

/* handle_args.c */
int		handle_args(int argc, char *argv[], t_table *tab);

#endif
