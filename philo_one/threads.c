/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 11:51:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 14:30:11 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"

int		initialize_philo(t_philo *philo, t_args *args, t_mutex *mutex)
{
	int i;

	i = 1;
	if (pthread_mutex_init(&mutex->eat_lock, NULL) ||
		pthread_mutex_init(&mutex->left_fork, NULL) ||
		pthread_mutex_init(&mutex->right_fork, NULL))
        return (-1);
	while (i < (args->nb_of_philo + 1))
	{
		philo[i].mutex = mutex;
		philo[i].args = args;
		philo[i].id = i;
		i++;
	}
	return (0);
}
