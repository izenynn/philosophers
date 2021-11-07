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
	return ("Error: not valid msg id\n");
}

	

static char	*get_msg(int msg)
{
	if (msg == MSG_FORK)
		return ("has taken a fork");
	if (msg == MSG_EAT)
		return ("is eating");
	if (msg == MSG_SLP)
		return ("is sleeping");
	if (msg == MSG_THK)
		return ("is thinking");
	if (msg == MSG_RIP)
		return ("R.I.P.");
	return ("Error: not valid msg id");
}

void	print_msg(t_philo *philo, int msg)
{
	size_t	t;

	t = get_time() - philo->tab->t_init;
	if (msg == MSG_EAT)
		printf("%s%-5ld %s%-3d %s%s #%-3d %s\n", BLU, t,
			MGN, philo->id, get_clr(msg), get_msg(msg), philo->eat_cnt, NOCOL);
	else
		printf("%s%-5ld %s%-3d %s%s%s\n", BLU, t,
			MGN, philo->id, get_clr(msg), get_msg(msg), NOCOL);
	/*ft_putnbr_fd(philo->id, STDOUT_FILENO);
	write(STDOUT_FILENO, "\t", 1);
	write(STDOUT_FILENO, get_msg(msg), ft_strlen(get_msg(msg)));*/
}
