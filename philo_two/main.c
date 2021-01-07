/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 11:38:02 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/07 14:40:54 by roybakker     ########   odam.nl         */
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

int    simulation_loop(t_philo *philo, t_args args, t_semaphore *semaphore)
{
    int i;

	i = 1;
    while (i < (args.nb_of_philo + 1))
    {
        philo[i].start_time = get_time();
        philo[i].eating_time = get_time();
   		if (pthread_create(&(philo[i].tid), NULL, &philo_simulation, &philo[i]))
        {
            semaphore->state = failure;
            i--;
            break ;
        }
        i++;
    }
    i--;
    while (i > 0)
    {
        pthread_join(philo[i].tid, NULL);
        i--;
    }
//    destroy_semaphore(philo);
    i = (semaphore->state == failure) ? -1 : 0;
    return (i);
}

int		initialize_philo(t_philo *philo, t_args *args, t_semaphore *semaphore)
{
	int i;

    semaphore->state = succes;
    semaphore->forks = sem_open("/forks", O_CREAT, 0644, args->nb_of_philo);
    if (semaphore->forks == SEM_FAILED)
        return (destroy_semaphore(philo));
    sem_unlink("/forks");
    semaphore->write_lock = sem_open("/write_lock", O_CREAT, 0644, 1);
    if (semaphore->write_lock == SEM_FAILED)
        return (destroy_semaphore(philo));
    sem_unlink("/write_lock");
    i = 1;
	while (i < (args->nb_of_philo + 1))
	{
        philo[i].health_lock = sem_open("/health_lock", O_CREAT, 0644, 1);
        if (philo[i].health_lock == SEM_FAILED)
            return (destroy_semaphore(philo));
        sem_unlink("/health_lock");
		philo[i].semaphore = semaphore;
		philo[i].args = args;
        philo[i].eat_cycles = 0;
		philo[i].id = i;
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
    t_args      args;
    t_semaphore semaphore;
    t_philo     *philosophers;

    write(STD_OUT, "time\tphilo\tstatus\n", 18);
	if (validate_args(&args, argc, argv))
        return (error_sequence("parsing error\n", 0));
    philosophers = malloc(sizeof(t_philo) * (args.nb_of_philo + 1));
    if (!philosophers)
       return (error_sequence("malloc fail\n", 0));
    if (initialize_philo(philosophers, &args, &semaphore) ||
        simulation_loop(philosophers, args, &semaphore))
        return (error_sequence("simulation fail\n", philosophers));
    free(philosophers);
    return (0);
}
