/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_life.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:50:06 by gkiala            #+#    #+#             */
/*   Updated: 2024/11/15 14:50:08 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	t_program		*program;

	philo = (t_philosopher *)arg;
	program = philo->program;
	while (1)
	{
		pthread_mutex_lock(&program->time_mutex);
		if (program->dead_flag)
		{
			pthread_mutex_unlock(&program->time_mutex);
			break ;
		}
		pthread_mutex_unlock(&program->time_mutex);
		ft_eating(philo, program);
		print_message(program, philo, "is sleeping");
		ft_usleep(program->time_to_sleep);
		print_message(program, philo, "is thinking");
	}
	return (NULL);
}

int	check_for_death(t_program *program, int i)
{
	long	t_l_meal;

	pthread_mutex_lock(&program->time_mutex);
	t_l_meal = get_current_time() - program->philos[i].last_meal_time;
	if (t_l_meal > program->time_to_die)
	{
		program->dead_flag = 1;
		pthread_mutex_unlock(&program->time_mutex);
		pthread_mutex_lock(&program->print_mutex);
		printf("\033[31m%ld %d died\033[0m\n",
			get_current_time() - program->start_time, program->philos[i].id);
		pthread_mutex_unlock(&program->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&program->time_mutex);
	return (0);
}

int	check_conditions(t_program *program)
{
	int	i;
	int	all_ate;

	i = 0;
	all_ate = 1;
	while (i < program->num_philosophers)
	{
		if (check_for_death(program, i))
			return (1);
		if (program->meals_required != -1
			&& program->philos[i].meals_eaten < program->meals_required)
			all_ate = 0;
		i++;
	}
	if (program->meals_required != -1 && all_ate)
	{
		pthread_mutex_lock(&program->time_mutex);
		program->dead_flag = 1;
		pthread_mutex_unlock(&program->time_mutex);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_program	*program;

	program = (t_program *)arg;
	while (1)
	{
		if (check_conditions(program))
			break ;
		usleep(500);
	}
	return (NULL);
}
