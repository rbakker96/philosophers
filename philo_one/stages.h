/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stages.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 16:36:27 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/23 11:07:12 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAGES_H
# define STAGES_H
# include "structs.h"

void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	healt_check(t_philo *philo);

#endif
