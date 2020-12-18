/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 15:07:12 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/18 15:26:45 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H
# include "structs.h"

long	timestamp(t_simulation_args *args);
void	eating(t_simulation_args *args);

#endif
