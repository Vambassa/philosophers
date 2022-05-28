/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitoring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:12:49 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 17:21:36 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	check_if_satisfied(t_each_philo *sophist)
{
	int	i;
	int	total_satisfaction;

	i = 0;
	total_satisfaction = 0;
	while (i < sophist->info->philo_num)
	{
		total_satisfaction += sophist->is_satisfied;
		i++;
	}
	if (total_satisfaction == sophist->info->philo_num)
		return (1);
	return (0);
}

static void	*check_philo_dead(void *sophist_info)
{
	t_each_philo	*sophist;

	sophist = (t_each_philo *)sophist_info;
	while (1)
	{
		if ((define_time() - sophist->last_eat) > sophist->info->time_to_die)
		{
			write_message(DEATH, define_time() - sophist->info->start_time, \
					sophist->index, sophist->info->write_mess_sem);
			exit(EXIT_SUCCESS);
		}
		if (sophist->info->num_must_eat > 0)
		{
			if (check_if_satisfied(sophist))
			{
				write_message(ALL_EAT, \
						define_time() - sophist->info->start_time, \
						0, sophist->info->write_mess_sem);
				exit(EXIT_SUCCESS);
			}
		}
		usleep(1000);
	}
}

void	life_monitoring(t_each_philo *sophist)
{
	pthread_t	philo_dead;

	if (pthread_create(&philo_dead, NULL, check_philo_dead, (void *)sophist))
		ft_print_error("Pthread error");
	if (pthread_detach(philo_dead))
		ft_print_error("Pthread error");
}
