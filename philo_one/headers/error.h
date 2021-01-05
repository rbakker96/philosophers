/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:57:23 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 14:58:17 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
#include "structs.h"

int		destroy_mutex(t_mutex *mutex, int i);
int		error_sequence(char *msg, t_philo *philo, pthread_mutex_t *mutex);

#endif
