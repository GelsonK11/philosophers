/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:09:55 by gkiala            #+#    #+#             */
/*   Updated: 2024/11/18 12:10:15 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_program *program, t_philosopher *philo,
	const char *message)
{
	char	*color;

	if (program->dead_flag)
		return ;
	if (ft_strcmp(message, "has taken a fork") == 0)
		color = "\033[32m";
	else if (ft_strcmp(message, "is eating") == 0)
		color = "\033[33m";
	else if (ft_strcmp(message, "is sleeping") == 0)
		color = "\033[34m";
	else if (ft_strcmp(message, "is thinking") == 0)
		color = "\033[36m";
	else
		color = "\033[0m";
	pthread_mutex_lock(&program->print_mutex);
	printf("%s%lu %d %s\033[0m\n", color,
		get_current_time() - program->start_time,
		philo->id, message);
	pthread_mutex_unlock(&program->print_mutex);
}

void	take_forks(t_philosopher *philo)
{
	t_program	*program;

	program = philo->program;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(program, philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_message(program, philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_message(program, philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_message(program, philo, "has taken a fork");
	}
}

void	release_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_eating(t_philosopher *philo, t_program *program)
{
	take_forks(philo);
	pthread_mutex_lock(&program->time_mutex);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&program->time_mutex);
	print_message(program, philo, "is eating");
	ft_usleep(program->time_to_eat);
	philo->meals_eaten++;
	release_forks(philo);
}
