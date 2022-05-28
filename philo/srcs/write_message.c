/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:12:20 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 17:25:12 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_message(int code, long long time, \
		int index, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	if (code == DEATH)
	{
		printf("%lld %i died\n", time, index);
		return ;
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
		printf("%llu All philosophers have had lunch\n", time);
	pthread_mutex_unlock(mutex);
}
