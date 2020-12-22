/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thinking.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 16:22:47 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 16:53:41 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stages.h"
#include "../support.h"

void		thinking(t_philo *philo)
{
	print_status(philo, "\tis thinking\n", philo->id, timestamp(philo));
}
