/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 20:07:32 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/03 14:02:15 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <pthread.h>
# include <sys/time.h>

typedef struct			s_mutex
{
	pthread_mutex_t		write_lock;
	pthread_mutex_t		*forks;
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
	pthread_mutex_t		eat_lock;
	long long			start_time;
	long long			eating_time;
	int					eat_cycles;
	int					id;
}						t_philo;

void					*philo_simulation(void *arguments);

#endif
