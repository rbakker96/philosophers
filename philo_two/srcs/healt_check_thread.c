/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   healt_check_thread.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:24:16 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/06 11:19:03 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/healt_check_thread.h"
#include "../headers/structs.h"
#include "../headers/time_calc.h"
#include "../headers/print_functions.h"
#include <unistd.h>

void	*health_check(void *arguments)
{
	t_philo *philo = (t_philo *)arguments;

    while (philo->args->state == alive && philo->mutex->state == succes &&
            philo->eat_cycles != philo->args->nb_of_must_eat)
	{
		pthread_mutex_lock(&philo->eat_lock);		//semaphore
		if ((get_time() - philo->eating_time) > philo->args->time_to_die)
		{
			print_status(philo, "\tis dead\n", philo->id, timestamp(philo));
			philo->args->state = dead;
		}
		pthread_mutex_unlock(&philo->eat_lock); 	//semaphore
		usleep(5000);
	}
	return NULL;
}
