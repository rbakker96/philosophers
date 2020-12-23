/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thinking.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 16:22:47 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/23 15:19:47 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stages.h"
#include "../support.h"

void		thinking(t_philo *philo)
{
	if (philo->args->state == dead)
		return ;
	print_status(philo, "\tis thinking\n", philo->id, timestamp(philo));
}
