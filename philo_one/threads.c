/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 11:51:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/18 15:42:42 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "threads.h"
#include "print_functions.h"

int		initialize_philo(t_simulation_args *args)
{
	int i;

	i = 1;
	args->philo = malloc(sizeof(t_philo) * (args->nb_of_philo + 1));
	if (!args->philo)
	{
		print(ERROR_OUT, "malloc failure\n");
		return (-1);
	}
	return (0);
}

int		initialize_mutex(t_simulation_args *args)
{
	int i;

	i = 1;
	if (pthread_mutex_init(&(args->mutex.eat_lock), NULL) ||
		pthread_mutex_init(&args->mutex.left_fork, NULL) ||
		pthread_mutex_init(&args->mutex.right_fork, NULL))
	{
		print(ERROR_OUT, "mutex init has failed\n");
        return (-1);
	}
	while (i < (args->nb_of_philo + 1))
	{
		if (pthread_create(&(args->philo[i].tid), NULL, &philo_simulation, args))
		{
			print(ERROR_OUT, "thread creation failure\n");
        	return (-1);
		}
		args->philo[i].nb = i;
		i++;
	}
	return (0);
}
