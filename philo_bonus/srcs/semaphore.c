/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:13:12 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 14:57:14 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	create_semaphore(t_philo_data *philo)
{
	sem_unlink("waiter_sem");
	philo->waiter_sem = sem_open("waiter_sem", O_CREAT, 0644, philo->philo_num);
	if (philo->waiter_sem == SEM_FAILED || !philo->waiter_sem)
		exit(EXIT_FAILURE);
	sem_unlink("write_mess_sem");
	philo->write_mess_sem = sem_open("write_mess_sem", O_CREAT, 0644, 1);
	if (philo->write_mess_sem == SEM_FAILED || !philo->write_mess_sem)
		exit(EXIT_FAILURE);
}

void	destroy_semaphore(t_philo_data *philo)
{
	if (sem_close(philo->write_mess_sem) == -1)
		exit(EXIT_FAILURE);
	if (sem_unlink("write_mess_sem") == -1)
		exit(EXIT_FAILURE);
	if (sem_close(philo->waiter_sem) == -1)
		exit(EXIT_FAILURE);
	if (sem_unlink("waiter_sem") == -1)
		exit(EXIT_FAILURE);
}
