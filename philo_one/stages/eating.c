/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eating.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 15:07:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/23 15:31:48 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stages.h"
#include "../support.h"
#include <unistd.h>

#include "stdio.h"

void	left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->left_fork);
	if (philo->args->state == dead)
		return ;
	print_status(philo, "\tgot left fork\n", philo->id, timestamp(philo));
}

void	right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->right_fork);
	if (philo->args->state == dead)
		return ;
	print_status(philo, "\tgot right fork\n", philo->id, timestamp(philo));
}

void	eating(t_philo *philo)
{
	if (eatingtime(philo) > philo->args->time_to_die)
	{
		print_status(philo, "\tis dead\n", philo->id, timestamp(philo));
		philo->args->state = dead;
		return ;
	}
	left_fork(philo);
	right_fork(philo);
	philo->eating_time = get_time();
	print_status(philo, "\tis eating\n", philo->id, timestamp(philo));
	usleep(philo->args->time_to_eat);
	pthread_mutex_unlock(&philo->mutex->right_fork);
	pthread_mutex_unlock(&philo->mutex->left_fork);
}
