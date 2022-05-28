/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:12:44 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 14:46:17 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	validate_arguments(t_philo_data *philo)
{
	if (philo->philo_num < 1 || philo->philo_num > 200 \
			|| philo->time_to_die < 60 || philo->time_to_eat < 60 \
			|| philo->time_to_sleep < 60 || philo->num_must_eat < 0)
		return (ft_print_error("Invalid arguments"));
	else
		return (0);
}

int	init_structure(t_philo_data *philo, int argc, char **argv)
{
	philo->philo_num = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->all_satisfied = 0;
	if (argc == 6)
		philo->num_must_eat = ft_atoi(argv[5]);
	else
		philo->num_must_eat = 0;
	philo->waiter_sem = NULL;
	philo->write_mess_sem = NULL;
	return (validate_arguments(philo));
}
