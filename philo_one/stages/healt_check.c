/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   healt_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 10:52:59 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/23 15:21:12 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../support.h"
#include "../structs.h"

void	healt_check(t_philo *philo)
{
	if (philo->args->state == dead)
		return ;
	if (eatingtime(philo) > philo->args->time_to_die)
	{
		print_status(philo, "\tis dead\n", philo->id, timestamp(philo));
		philo->args->state = dead;
	}
}
