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
# include <pthread.h>
# include <sys/time.h>

# define NOCOL "\033[0m"
# define RED "\033[1;31m"
# define YEL "\033[1;33m"
# define ORG "\033[0;33m"
# define GRN "\033[1;32m"
# define CIA "\033[1;36m"
# define DGRAY "\033[1;30m"
# define BLU "\033[1;34m"

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
	int				id;
	int				eat_cnt;
	size_t			last_eat;
	pthread_mutex_t	fork;
	struct s_philo	*r_philo;
	struct s_philo	*l_philo;
	struct s_table	*tab;
}	t_philo;

/* philo table struct */
typedef struct s_table
{
	int		t_die;
	int		t_eat;
	int		t_slp;
	int		tn_eat;
	int		n_philo;
	int		dead;
	int		eat_cnt_all;
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

/* philo_life.c */
void	*philo_life(void *arg);

#endif
