/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 20:07:32 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/06 11:39:41 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define STD_OUT 1
# define ERROR_OUT 2

# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct			s_mutex			//semaphore
{
	int					state;			//semaphore
	pthread_mutex_t		write_lock;		//semaphore
	pthread_mutex_t		*forks;			//semaphore
}						t_mutex;		//semaphore

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
	t_mutex				*mutex;			//semaphore
	t_args				*args;
	pthread_t			tid;
	pthread_mutex_t		eat_lock;		//semaphore of one
	long long			start_time;
	long long			eating_time;
	int					eat_cycles;
	int					id;
}						t_philo;

typedef enum			e_thread_status
{
	alive = 0,
	dead = 1,
	succes = 0,
	failure = 1,
	left = 0,
	right = 1
}						t_thread_status;

#endif
