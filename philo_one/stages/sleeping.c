/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sleeping.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 15:38:23 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 16:53:36 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stages.h"
#include "../support.h"
#include <unistd.h>

void		sleeping(t_philo *philo)
{
	print_status(philo, "\tis sleeping\n", philo->id, timestamp(philo));
	usleep(philo->args->time_to_sleep);
}
