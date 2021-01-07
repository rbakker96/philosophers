/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 14:56:12 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 19:33:47 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/time_calc.h"
#include <unistd.h>

void		sleeping(int total_time)
{
	long long time;

	time = get_time();
	while ((get_time() - time) < total_time)
		usleep(100);
}

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

	timestamp = (current.tv_sec * 1000 + current.tv_usec / 1000);

	return (timestamp - philo->start_time);
}
