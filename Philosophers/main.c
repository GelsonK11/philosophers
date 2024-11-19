/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:49:46 by gkiala            #+#    #+#             */
/*   Updated: 2024/11/15 14:49:48 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program	program;

	memset(&program, 0, sizeof(t_program));
	if (initialize_program(argc, argv, &program) != 0)
		return (1);
	create_threads(&program);
	destroy_mutexes(&program);
	return (0);
}
