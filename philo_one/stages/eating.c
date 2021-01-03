/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eating.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 15:07:21 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/03 15:24:36 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stages.h"
#include "../support.h"
#include <unistd.h>

void	grab_right_fork(t_philo *philo, int right_fork)
{
	pthread_mutex_lock(&philo->mutex->forks[right_fork]);
	print_status(philo, "\tgot right fork\n", philo->id, timestamp(philo));
}

void	grab_left_fork(t_philo *philo, int left_fork)
{
	pthread_mutex_lock(&philo->mutex->forks[left_fork]);
	print_status(philo, "\tgot left fork\n", philo->id, timestamp(philo));
}

void	eating(t_philo *philo)
{
	int fork[2];

	fork[left] = philo->id - 1;
	fork[right] = (philo->id == philo->args->nb_of_philo) ? 0 : philo->id;
	grab_right_fork(philo, fork[right]);
	grab_left_fork(philo, fork[left]);

	pthread_mutex_lock(&philo->eat_lock);
	philo->eating_time = get_time();
	print_status(philo, "\tis eating\n", philo->id, timestamp(philo));
	pthread_mutex_unlock(&philo->eat_lock);

	usleep(philo->args->time_to_eat);
	pthread_mutex_unlock(&philo->mutex->forks[fork[left]]);
	pthread_mutex_unlock(&philo->mutex->forks[fork[right]]);
}
