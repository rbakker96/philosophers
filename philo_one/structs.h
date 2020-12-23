/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 20:07:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/23 15:18:45 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <pthread.h>
# include <sys/time.h>

typedef struct			s_mutex
{
	pthread_mutex_t		write_lock;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		right_fork;
}						t_mutex;

typedef struct			s_args
{
	int					state;
	int					nb_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_must_eat;
}						t_args;

typedef struct			s_philo
{
	t_mutex				*mutex;
	t_args				*args;
	pthread_t			tid;
	long long			start_time;
	long long			eating_time;
	int					id;
}						t_philo;

void					*philo_simulation(void *arguments);

#endif
