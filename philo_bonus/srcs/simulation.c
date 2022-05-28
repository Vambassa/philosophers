/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:13:05 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 15:00:15 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	init_philo(t_philo_data *philo, t_each_philo *sophist)
{
	int	num;

	num = 0;
	while (num < philo->philo_num)
	{
		sophist[num].pid = fork();
		if (sophist[num].pid == -1)
			ft_print_error("Fork failed");
		else if (!sophist[num].pid)
		{
			sophist[num].index = num + 1;
			sophist[num].info = philo;
			sophist[num].count_eat_times = 0;
			sophist[num].is_satisfied = 0;
			lets_dine(&sophist[num], philo);
			return (0);
		}
		num++;
	}
	return (0);
}

int	start_simulation(t_philo_data *philo)
{
	t_each_philo	*sophist;

	sophist = (t_each_philo *)malloc(sizeof(t_each_philo) * philo->philo_num);
	if (!sophist)
		return (ft_print_error("Malloc failed"));
	create_semaphore(philo);
	philo->start_time = define_time();
	init_philo(philo, sophist);
	waitpid(-1, NULL, 0);
	kill_process(philo, sophist);
	destroy_semaphore(philo);
	free(sophist);
	return (0);
}
