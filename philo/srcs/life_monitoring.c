/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitoring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:11:55 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 13:01:53 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_if_satisfied(t_each_philo *sophist, t_philo_data *philo)
{
	int	i;
	int	total_satisfaction;

	i = 0;
	total_satisfaction = 0;
	while (i < philo->philo_num)
	{
		total_satisfaction += sophist[i].is_satisfied;
		i++;
	}
	if (total_satisfaction == philo->philo_num)
	{
		philo->all_satisfied = 1;
		return (1);
	}
	return (0);
}

void	check_philo_dead(t_philo_data *philo, t_each_philo *sophist)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->philo_num)
		{
			if ((define_time() - sophist[i].last_eat) > philo->time_to_die)
			{
				write_message(DEATH, define_time() - philo->start_time, \
						sophist[i].index, philo->write_mess_mutex);
				return ;
			}
			if (philo->num_must_eat > 0)
			{
				if (check_if_satisfied(sophist, philo))
					return ;
			}
			usleep(1000);
			i++;
		}
	}
}
