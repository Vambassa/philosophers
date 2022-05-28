/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:12:14 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 13:59:40 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_resources(t_each_philo *sophist, pthread_mutex_t *mutex_arr, \
		t_philo_data *philo)
{
	if (sophist)
		free(sophist);
	if (mutex_arr)
		free(mutex_arr);
	if (philo && philo->write_mess_mutex)
		free(philo->write_mess_mutex);
}

int	program_fail(t_philo_data *philo)
{
	free(philo);
	return (-1);
}

int	ft_print_error(const char *str)
{
	printf("%s\n", str);
	return (-1);
}

long long	define_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
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
