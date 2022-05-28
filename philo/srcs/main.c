/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:12:04 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 17:24:03 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo_data	*philo;

	if (argc < 5 || argc > 6)
		return (ft_print_error("Invalid number of arguments"));
	philo = (t_philo_data *)malloc(sizeof(t_philo_data));
	if (!philo)
		return (ft_print_error("Malloc failed"));
	if (init_structure(philo, argc, argv) < 0)
		return (program_fail(philo));
	if (argc == 6 && !philo->num_must_eat)
	{
		free(philo);
		return (ft_print_error("No need to eat"));
	}
	if (start_simulation(philo) < 0)
		return (program_fail(philo));
	if (philo->all_satisfied == 1)
		write_message(ALL_EAT, \
				define_time() - philo->start_time, \
				0, philo->write_mess_mutex);
	free(philo);
	return (0);
}
