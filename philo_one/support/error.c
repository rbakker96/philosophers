/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 15:32:03 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 13:45:31 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../support.h"
#include <stdlib.h>

int		error_sequence(char *msg, t_philo *philo, pthread_mutex_t *mutex)
{
	if (philo)
		free(philo);
	if (mutex)
		free(mutex);
	print(ERROR_OUT, msg);
	return (-1);
}
