/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 20:07:32 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/07 14:58:09 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define STD_OUT 1
# define ERROR_OUT 2

# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct			s_semaphore
{
	int					state;
	sem_t				*write_lock;
	sem_t				*health_lock;
	sem_t				*forks;
}						t_semaphore;

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
	t_semaphore			*semaphore;
	t_args				*args;
	pthread_t			tid;
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
