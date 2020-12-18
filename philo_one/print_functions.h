/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 15:29:25 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/18 15:17:34 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FUNCTIONS_H
# define PRINT_FUNCTIONS_H

# define STD_OUT 1
# define ERROR_OUT 2

int		print(int fd, char *str);
int		print_status(int status, int philo, long timestamp);

typedef enum		e_thread_status
{
	alive = 0,
	dead = 1,
	left = 0,
	right = 1,
	eat = 2,
	sleepp = 3,
	think = 4,
	died = 5
}					t_thread_status;

#endif
