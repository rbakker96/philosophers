/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   healt_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 10:52:59 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 13:49:05 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../support.h"
#include "../structs.h"
#include <unistd.h>

void	*health_check(void *arguments)
{
	t_philo *philo = (t_philo *)arguments;

    while (philo->args->state == alive && philo->mutex->state == succes &&
            philo->eat_cycles != philo->args->nb_of_must_eat)
	{
		pthread_mutex_lock(&philo->eat_lock);
		if ((get_time() - philo->eating_time) > philo->args->time_to_die)
		{
			print_status(philo, "\tis dead\n", philo->id, timestamp(philo));
			philo->args->state = dead;
		}
		pthread_mutex_unlock(&philo->eat_lock);
		usleep(5000);
	}
	return NULL;
}
