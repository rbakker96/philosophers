/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eating.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 15:07:21 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/03 14:34:58 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stages.h"
#include "../support.h"
#include <unistd.h>

void	grab_forks(t_philo *philo)
{
	int fork[2];

	fork[left] = philo->id - 1;
	fork[right] = (philo->id == philo->args->nb_of_philo) ? 0 : philo->id + 1;
	pthread_mutex_lock(&philo->mutex->forks[fork[left]]);
	print_status(philo, "\tgot left fork\n", philo->id, timestamp(philo));
	pthread_mutex_lock(&philo->mutex->forks[fork[right]]);
	print_status(philo, "\tgot right fork\n", philo->id, timestamp(philo));
}

void	eating(t_philo *philo)
{
	int fork[2];

	fork[left] = philo->id - 1;
	fork[right] = (philo->id == philo->args->nb_of_philo) ? 0 : philo->id + 1;
	grab_forks(philo);

	pthread_mutex_lock(&philo->eat_lock);
	philo->eating_time = get_time();
	print_status(philo, "\tis eating\n", philo->id, timestamp(philo));
	pthread_mutex_unlock(&philo->eat_lock);

	usleep(philo->args->time_to_eat);
	pthread_mutex_unlock(&philo->mutex->forks[fork[left]]);
	pthread_mutex_unlock(&philo->mutex->forks[fork[right]]);
}
