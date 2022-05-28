/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:13:18 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 17:22:10 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	write_message(int code, long long time, \
		int index, sem_t *write_mess_sem)
{
	sem_wait(write_mess_sem);
	if (code == DEATH)
	{
		printf("%lld %i died\n", time, index);
		exit(EXIT_SUCCESS);
	}
	else if (code == EAT)
		printf("%lld %i is eating\n", time, index);
	else if (code == FORK)
		printf("%lld %i has taken a fork\n", time, index);
	else if (code == THINK)
		printf("%lld %i is thinking\n", time, index);
	else if (code == SLEEP)
		printf("%lld %i is sleeping\n", time, index);
	else if (code == ALL_EAT)
	{
		printf("%lld All philosophers have had lunch\n", time);
		exit(EXIT_SUCCESS);
	}
	sem_post(write_mess_sem);
}
