/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:24:30 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/07 14:43:09 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/structs.h"
#include "../headers/philo_thread.h"
#include "../headers/healt_check_thread.h"
#include "../headers/print_functions.h"
#include "../headers/time_calc.h"
#include <unistd.h>

void	get_forks(t_philo *philo)
{
	sem_wait(philo->semaphore->forks);
	print_status(philo, "\tgot right fork\n", philo->id, timestamp(philo));
	sem_wait(philo->semaphore->forks);
	print_status(philo, "\tgot left fork\n", philo->id, timestamp(philo));
}

void	eating(t_philo *philo)
{
	get_forks(philo);
	sem_wait(philo->semaphore->health_lock);
	philo->eating_time = get_time();
	print_status(philo, "\tis eating\n", philo->id, timestamp(philo));
	sem_post(philo->semaphore->health_lock);
	sleeping(philo->args->time_to_eat);
	sem_post(philo->semaphore->forks);
	sem_post(philo->semaphore->forks);
}

void	*philo_simulation(void *arguments)
{
	t_philo *philo = (t_philo *)arguments;
    pthread_t health_monitor;

    if (pthread_create(&(health_monitor), NULL, &health_check, philo))
        return NULL;
    while (philo->args->state == alive && philo->semaphore->state == succes &&
            philo->eat_cycles != philo->args->nb_of_must_eat)
    {
        eating(philo);
        print_status(philo, "\tis sleeping\n", philo->id, timestamp(philo));
		sleeping(philo->args->time_to_sleep);
        print_status(philo, "\tis thinking\n", philo->id, timestamp(philo));
        philo->eat_cycles++;
    }
    return NULL;
}
