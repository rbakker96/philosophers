/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_calc.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:56:00 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/09 14:32:52 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_CALC_H
# define TIME_CALC_H
# include "structs.h"

void		sleeping(int total_time);
long long	get_time(void);
long long	timestamp(t_philo *philo);

#endif
