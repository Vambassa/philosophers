/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:13:12 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 15:46:00 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	kill_process(t_philo_data *philo, t_each_philo *sophist)
{
	int	num;

	num = 0;
	while (num < philo->philo_num)
	{
		kill(sophist[num].pid, SIGKILL);
		num++;
	}
}

long long	define_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	program_fail(t_philo_data *philo)
{
	free(philo);
	exit(EXIT_FAILURE);
}

int	ft_print_error(const char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

long long	ft_atoi(const char *str)
{
	size_t		i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > INT_MAX)
		return (-1);
	if (res < INT_MIN)
		return (0);
	return (res * sign);
}
