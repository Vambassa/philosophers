/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:12:31 by vambassa          #+#    #+#             */
/*   Updated: 2022/02/25 15:50:18 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define DEATH  0
# define EAT    1
# define FORK   2
# define THINK  3
# define SLEEP  4
# define ALL_EAT 5

typedef struct s_philo_data
{
	int			philo_num;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			num_must_eat;
	long long	start_time;
	int			all_satisfied;
	sem_t		*write_mess_sem;
	sem_t		*waiter_sem;
}	t_philo_data;

typedef struct s_each_philo
{
	int				index;
	pid_t			pid;
	t_philo_data	*info;
	int				count_eat_times;
	long long		last_eat;
	int				is_satisfied;
}	t_each_philo;

int			init_structure(t_philo_data *philo, int argc, char **argv);
void		create_semaphore(t_philo_data *philo);
void		destroy_semaphore(t_philo_data *philo);
void		*lets_dine(t_each_philo *sophist, t_philo_data *philo);
int			start_simulation(t_philo_data *philo);
void		life_monitoring(t_each_philo *sophist);
void		write_message(int code, long long time, \
		int index, sem_t *write_mess_sem);
void		kill_process(t_philo_data *philo, t_each_philo *sophist);
int			program_fail(t_philo_data *philo);
long long	define_time(void);
int			ft_print_error(const char *str);
long long	ft_atoi(const char *str);

#endif
