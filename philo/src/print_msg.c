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

static char	*get_msg(int msg)
{
	if (msg == MSG_FORK)
		return ("has taken a fork\n");
	if (msg == MSG_EAT)
		return ("is eating\n");
	if (msg == MSG_SLP)
		return ("is sleeping\n");
	if (msg == MSG_THK)
		return ("is thinking\n");
	if (msg == MSG_RIP)
		return ("R.I.P.\n");
	return ("Error: not valid msg id\n");
}

void	print_msg(t_philo *philo, int msg)
{
	ft_putnbr_fd(philo->id, STDOUT_FILENO);
	write(STDOUT_FILENO, "\t", 1);
	write(STDOUT_FILENO, get_msg(msg), ft_strlen(get_msg(msg)));
}
