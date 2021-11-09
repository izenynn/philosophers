/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:27:48 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/11/09 11:54:23 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

/* get message color */
static char	*get_clr(int msg)
{
	if (msg == MSG_FORK)
		return (YEL);
	if (msg == MSG_EAT)
		return (GRN);
	if (msg == MSG_SLP)
		return (BLU);
	if (msg == MSG_THK)
		return (CIA);
	if (msg == MSG_RIP)
		return (RED);
	return ("Error: not valid msg id");
}

/* get message string */
static char	*get_msg(int msg)
{
	if (msg == MSG_FORK)
		return ("(-3-) has taken a fork");
	if (msg == MSG_EAT)
		return ("(^o^) is eating");
	if (msg == MSG_SLP)
		return ("(u.u) is sleeping");
	if (msg == MSG_THK)
		return ("(7.7) is thinking");
	if (msg == MSG_RIP)
		return ("(x.x) died");
	return ("Error: not valid msg id");
}

/* print philo status messages */
void	print_msg(t_philo *philo, int msg)
{
	size_t	t;

	t = get_time() - philo->tab->t_init;
	sem_wait(philo->tab->print);
	if (!philo->tab->dead && !philo->tab->eaten_all)
	{
		printf(DGRAY"%6ld ms", t);
		printf(MGN" %3d ", philo->id);
		printf("%s%s", get_clr(msg), get_msg(msg));
		if (msg == MSG_EAT)
			printf(" #%d", philo->eat_cnt);
		printf("\n");
	}
	sem_post(philo->tab->print);
}
