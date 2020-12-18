/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 20:07:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/18 15:39:20 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <sys/time.h>
# include <pthread.h>


typedef struct			s_mutex_rscs
{
	pthread_mutex_t		eat_lock;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		right_fork;
}						t_mutex_rscs;

typedef struct			s_philo
{
	pthread_t			tid;
	int					nb;
}						t_philo;

typedef struct			s_simulation_args
{
	t_mutex_rscs		mutex;
	t_philo				*philo;
	struct timeval		time;
	int					nb_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_must_eat;
}						t_simulation_args;

void					*philo_simulation(void *arguments);

#endif
