/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:12:09 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 12:59:51 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	destroy_mutex(t_philo_data *philo, t_each_philo *sophist)
{
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		pthread_mutex_destroy(sophist[i].left_fork);
		i++;
	}
	pthread_mutex_destroy(philo->write_mess_mutex);
}

static int	create_philo_threads(t_each_philo *sophist, t_philo_data *philo)
{
	int			num;
	pthread_t	*soph_thr_id;

	soph_thr_id = (pthread_t *) malloc(sizeof(pthread_t) * philo->philo_num);
	if (!soph_thr_id)
		return (ft_print_error("Malloc failed"));
	num = 0;
	while (num < philo->philo_num)
	{
		if (pthread_create(&soph_thr_id[num], NULL, \
					lets_dine, (void *)&sophist[num]))
			return (ft_print_error("Pthread failure"));
		if (pthread_detach(soph_thr_id[num]))
			return (ft_print_error("Pthread failure"));
		num++;
	}
	check_philo_dead(philo, sophist);
	destroy_mutex(philo, sophist);
	free(soph_thr_id);
	return (0);
}

static void	init_philo(t_each_philo *sophist, \
		t_philo_data *philo, pthread_mutex_t *mutex_arr)
{
	int	num;

	num = 0;
	while (num < philo->philo_num)
	{
		pthread_mutex_init(&mutex_arr[num], NULL);
		sophist[num].index = num + 1;
		sophist[num].info = philo;
		sophist[num].left_fork = &mutex_arr[num];
		sophist[num].right_fork = &mutex_arr[(num + 1) % philo->philo_num];
		sophist[num].count_eat_times = 0;
		sophist[num].is_satisfied = 0;
		num++;
	}
}

int	start_simulation(t_philo_data *philo)
{
	pthread_mutex_t	*mutex_arr;
	t_each_philo	*sophist;

	sophist = (t_each_philo *)malloc(sizeof(t_each_philo) * philo->philo_num);
	if (!sophist)
		return (ft_print_error("Malloc failed"));
	mutex_arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* philo->philo_num);
	if (!mutex_arr)
	{
		free_resources(sophist, mutex_arr, philo);
		return (ft_print_error("Malloc failed"));
	}
	init_philo(sophist, philo, mutex_arr);
	philo->write_mess_mutex = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->write_mess_mutex, NULL);
	philo->start_time = define_time();
	if (create_philo_threads(sophist, philo) < 0)
	{
		free_resources(sophist, mutex_arr, philo);
		return (-1);
	}
	free_resources(sophist, mutex_arr, philo);
	return (0);
}
