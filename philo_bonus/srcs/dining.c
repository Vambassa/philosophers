/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:12:39 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 17:19:24 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	wait_time(long long time)
{
	long long	end_time;

	end_time = define_time() + time;
	while (define_time() < end_time)
		usleep(time);
}

static void	sophist_eating(t_each_philo *sophist, t_philo_data *philo)
{
	sem_wait(philo->waiter_sem);
	write_message(FORK, define_time() - philo->start_time, \
			sophist->index, philo->write_mess_sem);
	sem_wait(philo->waiter_sem);
	write_message(FORK, define_time() - philo->start_time, \
			sophist->index, philo->write_mess_sem);
	write_message(EAT, define_time() - philo->start_time, \
			sophist->index, philo->write_mess_sem);
	sophist->last_eat = define_time();
	wait_time(philo->time_to_eat);
	sem_post(philo->waiter_sem);
	sem_post(philo->waiter_sem);
	if (philo->num_must_eat > 0)
	{
		sophist->count_eat_times++;
		if (sophist->count_eat_times == philo->num_must_eat)
			sophist->is_satisfied = 1;
	}
}

static void	sophist_thinking(t_each_philo *sophist, t_philo_data *philo)
{
	write_message(THINK, define_time() - philo->start_time, \
			sophist->index, philo->write_mess_sem);
}

static void	sophist_sleeping(t_each_philo *sophist, t_philo_data *philo)
{
	write_message(SLEEP, define_time() - philo->start_time, \
			sophist->index, philo->write_mess_sem);
	wait_time(philo->time_to_sleep);
}

void	*lets_dine(t_each_philo *sophist, t_philo_data *philo)
{
	sophist->last_eat = define_time();
	if (sophist->index % 2)
		usleep(500);
	life_monitoring(sophist);
	while (1)
	{
		sophist_eating(sophist, philo);
		sophist_sleeping(sophist, philo);
		sophist_thinking(sophist, philo);
	}
}
