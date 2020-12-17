/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 11:50:58 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/15 14:59:39 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H
# include "structs.h"

int		initialize_philo(t_simulation_args *args);
int		initialize_mutex(t_simulation_args *args);

#endif
