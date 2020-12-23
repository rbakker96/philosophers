/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sleeping.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 15:38:23 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/23 15:19:39 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stages.h"
#include "../support.h"
#include <unistd.h>

void		sleeping(t_philo *philo)
{
	if (philo->args->state == dead)
		return ;
	print_status(philo, "\tis sleeping\n", philo->id, timestamp(philo));
	usleep(philo->args->time_to_sleep);
}
