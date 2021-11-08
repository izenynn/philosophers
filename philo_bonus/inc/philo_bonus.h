/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:06:52 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/11/09 00:13:05 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/wait.h>

# define NOCOL "\033[0m"
# define RED "\033[1;31m"
# define YEL "\033[1;33m"
# define ORG "\033[0;33m"
# define GRN "\033[1;32m"
# define CIA "\033[1;36m"
# define DGRAY "\033[1;90m"
# define BLU "\033[1;34m"
# define MGN "\033[1;35m"

# define ALIVE_EXIT 0
# define DEAD_EXIT 1

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
	struct s_philo	*r_philo;
	struct s_philo	*l_philo;
	struct s_table	*tab;
	pid_t			pid;
	pthread_t		check_dead;
}	t_philo;

/* philo table struct */
typedef struct s_table
{
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				n_eat;
	int				n_philos;
	int				eaten_all;
	int				dead;
	size_t			t_init;
	t_philo			*philos;
	sem_t			*print;
	sem_t			*check;
	sem_t			*forks;
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

/* philo_utils.c */
void	exit_philo(t_table *tab);
size_t	get_time(void);
void	hypnos(t_table *tab, size_t t_slp);

#endif
