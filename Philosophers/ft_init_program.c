/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:02:49 by gkiala            #+#    #+#             */
/*   Updated: 2024/11/15 15:02:51 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arguments(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philo <# philosophers> <time to die><time to eat>"
			"<time to sleep> [# times each philosopher must eat]\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_is_digit(argv[i]) || ft_atoi(argv[i]) <= 0)
		{
			printf("Error: Arguments must be positive integers.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	initialize_single_philosopher(t_program *program)
{
	pthread_mutex_init(&program->forks[0], NULL);
	program->philos[0].id = 1;
	program->philos[0].meals_eaten = 0;
	program->philos[0].last_meal_time = get_current_time();
	program->philos[0].left_fork = &program->forks[0];
	program->philos[0].right_fork = NULL;
	program->philos[0].program = program;
	print_message(program, &program->philos[0], "has taken a fork");
	pthread_mutex_lock(&program->forks[0]);
	pthread_mutex_lock(&program->print_mutex);
	if (!program->dead_flag)
	{
		program->dead_flag = 1;
	}
	pthread_mutex_unlock(&program->print_mutex);
	pthread_mutex_unlock(&program->forks[0]);
	pthread_mutex_destroy(&program->forks[0]);
	return (1);
}

void	initialize_philosophers(t_program *program)
{
	int	i;
	int	num_philo;

	i = 0;
	num_philo = program->num_philosophers;
	while (i < num_philo)
	{
		pthread_mutex_init(&program->forks[i], NULL);
		program->philos[i].id = i + 1;
		program->philos[i].meals_eaten = 0;
		program->philos[i].last_meal_time = 0;
		program->philos[i].left_fork = &program->forks[i];
		program->philos[i].right_fork = &program->forks[(i + 1) % num_philo];
		program->philos[i].program = program;
		i++;
	}
}

int	initialize_program(int argc, char **argv, t_program *program)
{
	if (check_arguments(argc, argv) != 0)
		return (1);
	program->num_philosophers = ft_atoi(argv[1]);
	program->time_to_die = ft_atoi(argv[2]);
	program->time_to_eat = ft_atoi(argv[3]);
	program->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		program->meals_required = ft_atoi(argv[5]);
	else
		program->meals_required = -1;
	program->dead_flag = 0;
	program->start_time = get_current_time();
	pthread_mutex_init(&program->print_mutex, NULL);
	if (program->num_philosophers == 1)
	{
		initialize_single_philosopher(program);
		return (0);
	}
	if (program->num_philosophers < 1 || program->num_philosophers > MAX_PHILOS)
	{
		printf("Error: Invalid number of philosophers (1-%d).\n", MAX_PHILOS);
		return (1);
	}
	initialize_philosophers(program);
	return (0);
}
