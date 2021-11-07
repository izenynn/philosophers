/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:27:48 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/11/04 13:27:55 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
		return ("(-.-) has taken a fork");
	if (msg == MSG_EAT)
		return ("(^o^) is eating");
	if (msg == MSG_SLP)
		return ("(u.u) is sleeping");
	if (msg == MSG_THK)
		return ("(7.7) is thinking");
	if (msg == MSG_RIP)
		return ("(x.x) R.I.P.");
	return ("Error: not valid msg id");
}

/* print philo status messages */
void	print_msg(t_philo *philo, int msg)
{
	size_t	t;

	/* get time stamp in ms */
	t = get_time() - philo->tab->t_init;
	/* block mutex for print */
	pthread_mutex_lock(&philo->tab->print);
	/* print status message */
	if (!philo->tab->dead)
	{
		if (msg == MSG_EAT)
			printf("%s%5ld ms %s%3d %s%s #%d %s\n", DGRAY, t,
				MGN, philo->id, get_clr(msg), get_msg(msg), philo->eat_cnt, NOCOL);
		else
			printf("%s%5ld ms %s%3d %s%s%s\n", DGRAY, t,
				MGN, philo->id, get_clr(msg), get_msg(msg), NOCOL);
	}
	/* unlock mutex */
	pthread_mutex_unlock(&philo->tab->print);
}
