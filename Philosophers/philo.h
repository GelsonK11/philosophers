/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:48:33 by gkiala            #+#    #+#             */
/*   Updated: 2024/10/11 10:51:39 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>
# include <string.h>

# define MAX_PHILOS 200

typedef struct s_philosopher
{
	int					id;
	_Atomic int			meals_eaten;
	struct s_program	*program;
	unsigned long		last_meal_time;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}	t_philosopher;

typedef struct s_program
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	_Atomic int		dead_flag;
	unsigned long	start_time;
	pthread_mutex_t	forks[MAX_PHILOS];
	pthread_mutex_t	print_mutex;
	t_philosopher	philos[MAX_PHILOS];
	pthread_mutex_t	time_mutex;
}	t_program;

int		ft_usleep(size_t milliseconds);
int		ft_is_digit(char *str);
int		ft_atoi(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		initialize_program(int argc, char **argv, t_program *program);
size_t	get_current_time(void);
void	*philosopher_routine(void *arg);
void	*monitor(void *arg);
void	create_threads(t_program *program);
void	destroy_mutexes(t_program *program);
void	print_message(t_program *program, t_philosopher *philo,
			const char *message);
void	ft_eating(t_philosopher *philo, t_program *program);

#endif
