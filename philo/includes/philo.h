/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:11:27 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 14:06:05 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define DEATH  0
# define EAT    1
# define FORK   2
# define THINK  3
# define SLEEP  4
# define ALL_EAT 5

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_philo_data
{
	int				philo_num;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				num_must_eat;
	long long		start_time;
	int				all_satisfied;
	pthread_mutex_t	*write_mess_mutex;
}	t_philo_data;

typedef struct s_each_philo
{
	int				index;
	t_philo_data	*info;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				count_eat_times;
	long long		last_eat;
	int				is_satisfied;
}	t_each_philo;

int			init_structure(t_philo_data *philo, int argc, char **argv);
int			start_simulation(t_philo_data *philo);
void		check_philo_dead(t_philo_data *philo, t_each_philo *sophist);
void		write_message(int code, long long time, int index, \
		pthread_mutex_t *mutex);
void		*lets_dine(void *sophist_data);
long long	ft_atoi(const char *str);
long long	define_time(void);
void		free_resources(t_each_philo *sophist, pthread_mutex_t *mutex_arr, \
		t_philo_data *philo);
int			program_fail(t_philo_data *philo);
int			ft_print_error(const char *str);

#endif
