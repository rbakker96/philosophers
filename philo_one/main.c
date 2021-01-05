/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 11:38:02 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 20:11:58 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/structs.h"
#include "headers/philo_thread.h"
#include "headers/input_validation.h"
#include "headers/time_calc.h"
#include "headers/print_functions.h"
#include "headers/error.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

int    simulation_loop(t_philo *philo, t_args args, t_mutex *mutex)
{
    int i;

	i = 1;
    while (i < (args.nb_of_philo + 1))
    {
        philo[i].start_time = get_time();
        philo[i].eating_time = get_time();
   		if (pthread_create(&(philo[i].tid), NULL, &philo_simulation, &philo[i]))
        {
            mutex->state = failure;
            i--;
            break ;
        }
        i++;
    }
    while (i > 0)
    {
        pthread_join(philo[i].tid, NULL);
        i--;
    }
    destroy_mutex(mutex, args.nb_of_philo);
    i = (mutex->state == failure) ? -1 : 0;
    return (i);
}

int		initialize_philo(t_philo *philo, t_args *args, t_mutex *mutex)
{
	int i;

    i = 0;
    mutex->state = succes;
	if (pthread_mutex_init(&mutex->write_lock, NULL))
        return (-1);
    while (i < args->nb_of_philo)
    {
        if (pthread_mutex_init(&mutex->forks[i], NULL))
            return (destroy_mutex(mutex, i));
        i++;
    }
    i = 1;
	while (i < (args->nb_of_philo + 1))
	{
		philo[i].mutex = mutex;
		philo[i].args = args;
        philo[i].eat_cycles = 0;
		philo[i].id = i;
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
    t_args	    args;
    t_mutex     mutex;
    t_philo     *philosophers;

    write(STD_OUT, "time\tphilo\tstatus\n", 18);
	if (validate_args(&args, argc, argv))
        return (error_sequence("parsing error\n", 0, 0));
    philosophers = malloc(sizeof(t_philo) * (args.nb_of_philo + 1));
    if (!philosophers)
       return (error_sequence("malloc fail\n", 0, 0));
    mutex.forks = malloc(sizeof(pthread_mutex_t) * args.nb_of_philo);
    if (!mutex.forks)
        return (error_sequence("malloc fail\n", philosophers, 0));
    if (initialize_philo(philosophers, &args, &mutex) ||
        simulation_loop(philosophers, args, &mutex))
        return (error_sequence("simulation fail\n", philosophers, mutex.forks));
    free(philosophers);
    free(mutex.forks);
    return (0);
}
