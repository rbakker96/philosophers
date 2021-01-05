/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:24:30 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 15:27:44 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/structs.h"
#include "../headers/philo_thread.h"
#include "../headers/healt_check_thread.h"
#include "../headers/print_functions.h"
#include "../headers/time_calc.h"
#include <unistd.h>

void	left_fork_first(t_philo *philo, int left_fork, int right_fork)
{
	pthread_mutex_lock(&philo->mutex->forks[left_fork]);
	print_status(philo, "\tgot left fork\n", philo->id, timestamp(philo));
	pthread_mutex_lock(&philo->mutex->forks[right_fork]);
	print_status(philo, "\tgot right fork\n", philo->id, timestamp(philo));
}

void	right_fork_first(t_philo *philo, int left_fork, int right_fork)
{
	pthread_mutex_lock(&philo->mutex->forks[right_fork]);
	print_status(philo, "\tgot right fork\n", philo->id, timestamp(philo));
	pthread_mutex_lock(&philo->mutex->forks[left_fork]);
	print_status(philo, "\tgot left fork\n", philo->id, timestamp(philo));
}

void	eating(t_philo *philo)
{
	int fork[2];

	fork[left] = philo->id - 1;
	fork[right] = (philo->id == philo->args->nb_of_philo) ? 0 : philo->id;
	if (philo->id % 2 == 0)
		right_fork_first(philo, fork[left], fork[right]);
	else
		left_fork_first(philo, fork[left], fork[right]);

	pthread_mutex_lock(&philo->eat_lock);
	philo->eating_time = get_time();
	print_status(philo, "\tis eating\n", philo->id, timestamp(philo));
	pthread_mutex_unlock(&philo->eat_lock);

	usleep(philo->args->time_to_eat);
	pthread_mutex_unlock(&philo->mutex->forks[fork[left]]);
	pthread_mutex_unlock(&philo->mutex->forks[fork[right]]);
}

void	*philo_simulation(void *arguments)
{
	t_philo *philo = (t_philo *)arguments;
    pthread_t health_monitor;

    if (pthread_create(&(health_monitor), NULL, &health_check, philo))
        return NULL;
    while (philo->args->state == alive && philo->mutex->state == succes &&
            philo->eat_cycles != philo->args->nb_of_must_eat)
    {
        eating(philo);
        print_status(philo, "\tis sleeping\n", philo->id, timestamp(philo));
	    usleep(philo->args->time_to_sleep);
        print_status(philo, "\tis thinking\n", philo->id, timestamp(philo));
        philo->eat_cycles++;
    }
    return NULL;
}
