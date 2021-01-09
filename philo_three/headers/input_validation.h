/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 15:02:31 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/09 14:56:35 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_VALIDATION_H
# define INPUT_VALIDATION_H
# include "structs.h"

int		validate_args(t_args *args, int argc, char **argv);

#endif
