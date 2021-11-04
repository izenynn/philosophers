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

/* message type enum */
enum e_msg {
	MSG_FORK = 0,
	MSG_EAT,
	MSG_SLP,
	MSG_THK,
	MSG_RIP
};

/* philo struct */
typedef struct s_philo
{
	int	id;
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
int		ft_putnbr_fd(int n, int fd);

/* handle_args.c */
int		handle_args(int argc, char *argv[], t_table *tab);

/* print_msg.c */
void	print_msg(t_philo *philo, int msg);

#endif
