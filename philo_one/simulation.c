/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 15:07:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/18 15:55:41 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include "print_functions.h"
#include <unistd.h>

long	timestamp(t_simulation_args *args)
{
	struct timeval current;
	long long timestamp;
	gettimeofday(&current, NULL);

	timestamp = (current.tv_sec * 1000 + current.tv_usec / 1000) -
			(args->time.tv_sec * 1000 + args->time.tv_usec / 1000);

	return (timestamp);
}

void	left_fork(t_simulation_args *args)
{
	pthread_mutex_lock(&args->mutex.left_fork);

	print_status(left, args->philo->nb, timestamp(args));

	pthread_mutex_unlock(&args->mutex.left_fork);
}

void	right_fork(t_simulation_args *args)
{
	pthread_mutex_lock(&args->mutex.right_fork);

	print_status(right, args->philo->nb, timestamp(args));

	pthread_mutex_unlock(&args->mutex.right_fork);
}

void	eating(t_simulation_args *args)
{
	pthread_mutex_lock(&args->mutex.eat_lock);
	left_fork(args);
	right_fork(args);
	print_status(eat, args->philo->nb, timestamp(args));
	usleep(args->time_to_eat);
	pthread_mutex_unlock(&args->mutex.eat_lock);
}
