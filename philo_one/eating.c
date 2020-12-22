/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eating.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 15:07:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 15:30:59 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "eating.h"
#include "time_calc.h"
#include "print_functions.h"
#include <unistd.h>

void	left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->left_fork);

	print_status("\thas taken a left fork\n", philo->id, timestamp(philo));

	pthread_mutex_unlock(&philo->mutex->left_fork);
}

void	right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->right_fork);

	print_status("\thas taken a right fork\n", philo->id, timestamp(philo));

	pthread_mutex_unlock(&philo->mutex->right_fork);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->eat_lock);
	left_fork(philo);
	right_fork(philo);
	print_status("\tis eating\n", philo->id, timestamp(philo));
	usleep(philo->args->time_to_eat);
	pthread_mutex_unlock(&philo->mutex->eat_lock);
}
