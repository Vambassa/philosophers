/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:12:53 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 15:12:23 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo_data	*philo;

	if (argc < 5 || argc > 6)
		ft_print_error("Invalid number of arguments");
	philo = (t_philo_data *)malloc(sizeof(t_philo_data));
	if (!philo)
		ft_print_error("Malloc failed");
	if (init_structure(philo, argc, argv) < 0)
		program_fail(philo);
	if (argc == 6 && !philo->num_must_eat)
		ft_print_error("No need to eat");
	start_simulation(philo);
	free(philo);
	return (0);
}
