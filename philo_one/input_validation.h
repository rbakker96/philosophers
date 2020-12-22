/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 15:20:25 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 14:19:01 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_VALIDATION_H
# define INPUT_VALIDATION_H
# include "structs.h"

int		validate_args(t_args *args, int argc, char **argv);

#endif
