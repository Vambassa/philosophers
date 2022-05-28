/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:11:38 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 13:52:33 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	wait_time(int time)
{
	long long	end_time;

	end_time = define_time() + time;
	while (define_time() < end_time)
		usleep(time);
}

static void	sophist_eating(t_each_philo *sophist)
{
	pthread_mutex_lock(sophist->left_fork);
	write_message(FORK, define_time() - sophist->info->start_time, \
			sophist->index, sophist->info->write_mess_mutex);
	pthread_mutex_lock(sophist->right_fork);
	write_message(FORK, define_time() - sophist->info->start_time, \
			sophist->index, sophist->info->write_mess_mutex);
	write_message(EAT, define_time() - sophist->info->start_time, \
			sophist->index, sophist->info->write_mess_mutex);
	sophist->last_eat = define_time();
	wait_time(sophist->info->time_to_eat);
	pthread_mutex_unlock(sophist->left_fork);
	pthread_mutex_unlock(sophist->right_fork);
	if (sophist->info->num_must_eat > 0)
	{
		sophist->count_eat_times++;
		if (sophist->count_eat_times == sophist->info->num_must_eat)
			sophist->is_satisfied = 1;
	}
}

static void	sophist_thinking(t_each_philo *sophist)
{
	write_message(THINK, define_time() - sophist->info->start_time, \
			sophist->index, sophist->info->write_mess_mutex);
}

static void	sophist_sleeping(t_each_philo *sophist)
{
	write_message(SLEEP, define_time() - sophist->info->start_time, \
			sophist->index, sophist->info->write_mess_mutex);
	wait_time(sophist->info->time_to_sleep);
}

void	*lets_dine(void *sophist_data)
{
	t_each_philo	*sophist;

	sophist = (t_each_philo *)sophist_data;
	sophist->last_eat = define_time();
	sophist->count_eat_times = 0;
	if (sophist->index % 2)
		usleep(1000);
	while (1)
	{
		sophist_eating(sophist);
		sophist_thinking(sophist);
		sophist_sleeping(sophist);
	}
}
