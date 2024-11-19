/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthreads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:07:59 by gkiala            #+#    #+#             */
/*   Updated: 2024/11/15 15:08:00 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_program *program)
{
	pthread_t	threads[MAX_PHILOS];
	pthread_t	observer;
	int			i;

	i = 0;
	while (i < program->num_philosophers)
	{
		program->philos[i].last_meal_time = get_current_time();
		program->philos[i].meals_eaten = 0;
		program->philos[i].program = program;
		pthread_create(&threads[i], NULL, philosopher_routine,
			&program->philos[i]);
		i++;
	}
	pthread_create(&observer, NULL, monitor, program);
	i = 0;
	while (i < program->num_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	pthread_join(observer, NULL);
}

void	destroy_mutexes(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->num_philosophers)
	{
		pthread_mutex_destroy(&program->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->print_mutex);
}
