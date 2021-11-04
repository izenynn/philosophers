/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:38:39 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/11/04 11:38:40 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	short			sign;
	unsigned char	digit;
	unsigned long	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' && str++)
		sign = -1;
	else if (*str == '+')
		str++;
	while (1)
	{
		digit = *str++ - '0';
		if (digit > 9)
			break ;
		result = result * 10 + digit;
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (result > 2147483648 && sign == -1)
			return (0);
	}
	return (result * sign);
}

int	ft_putnbr_fd(int n, int fd)
{
	int					cnt;
	short				sign;
	unsigned int		pow_ten;
	char				c;

	cnt = 0;
	pow_ten = 1;
	sign = 0;
	if (n < 0 && ++sign)
		n = -n;
	while (n / pow_ten / 10)
		pow_ten *= 10;
	if (sign)
		cnt += write(fd, "-", 1);
	while (pow_ten)
	{
		c = n / pow_ten + '0';
		cnt += write(fd, &c, 1);
		n %= pow_ten;
		pow_ten /= 10;
	}
	return (cnt);
}
