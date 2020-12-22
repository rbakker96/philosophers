/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 14:56:12 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 16:54:41 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../support.h"

long long	get_time()
{
	struct timeval current;
	long long time_in_ms;

	gettimeofday(&current, NULL);
	time_in_ms = (current.tv_sec * 1000 + current.tv_usec / 1000);

	return (time_in_ms);
}

long long	timestamp(t_philo *philo)
{
	struct timeval current;
	long long timestamp;
	gettimeofday(&current, NULL);

	timestamp = (current.tv_sec * 1000 + current.tv_usec / 1000)
				- philo->start_time;

	return (timestamp);
}
