/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 15:32:03 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 20:11:35 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include "../headers/utils.h"
#include <stdlib.h>
#include <unistd.h>

int		destroy_mutex(t_mutex *mutex, int i)
{
    i--;
    while (i >= 0)
    {
        pthread_mutex_destroy(&mutex->forks[i]);
    	i--;
	}
	pthread_mutex_destroy(&mutex->write_lock);
	return (-1);
}

int		error_sequence(char *msg, t_philo *philo, pthread_mutex_t *mutex)
{
	if (philo)
		free(philo);
	if (mutex)
		free(mutex);
	write(ERROR_OUT, msg, ft_strlen(msg));
	return (-1);
}
