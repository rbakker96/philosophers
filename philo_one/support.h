/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   support.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 16:42:21 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 13:47:03 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPPORT_H
# define SUPPORT_H
# include "structs.h"

# define STD_OUT 1
# define ERROR_OUT 2

int			error_sequence(char *msg, t_philo *philo, pthread_mutex_t *mutex);

int			validate_args(t_args *args, int argc, char **argv);

int			parse_args(t_args *args, int argc, char **argv);

void		print_nb(int fd, long n); // remove later
int			print(int fd, char *str);
void		print_status(t_philo *philo, char *status, int id, long timestamp);

long long	get_time();
long long	timestamp(t_philo *philo);

typedef enum		e_thread_status
{
	alive = 0,
	dead = 1,
	succes = 0,
	failure = 1,
	left = 0,
	right = 1
}					t_thread_status;

#endif
