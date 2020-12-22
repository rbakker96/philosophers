/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 11:50:58 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 14:19:53 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H
# include "structs.h"

int		initialize_philo(t_philo *philo, t_args *args, t_mutex *mutex);

#endif
