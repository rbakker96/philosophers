/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 15:26:07 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 15:21:48 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../headers/print_functions.h"
#include "../headers/utils.h"

void		print_status(t_philo *philo, char *status, int id, long timestamp)
{
	pthread_mutex_lock(&philo->mutex->write_lock);
	if (philo->args->state != dead)
	{
		print_nb(STD_OUT, timestamp);
		write(STD_OUT, "\t", 1);
		print_nb(STD_OUT, id);
		write(STD_OUT, status, ft_strlen(status));
	}
	pthread_mutex_unlock(&philo->mutex->write_lock);
}
