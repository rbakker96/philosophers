/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 11:38:02 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/03 14:00:44 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stages.h"
#include "support.h"
#include "structs.h"
#include <stdlib.h>
#include <unistd.h>

void    print_args(t_args args)
{
    print(STD_OUT, "nb of philo = ");
    print_nb(STD_OUT, args.nb_of_philo);
    print(STD_OUT, "\ntime to die= ");
    print_nb(STD_OUT, args.time_to_die);
    print(STD_OUT, "\ntime to eat = ");
    print_nb(STD_OUT, args.time_to_eat);
    print(STD_OUT, "\nntime to sleep = ");
    print_nb(STD_OUT, args.time_to_sleep);
    print(STD_OUT, "\nnb of must eat = ");
    print_nb(STD_OUT, args.nb_of_must_eat);
    print(STD_OUT, "\n\n");
}

void	*philo_simulation(void *arguments)
{
	t_philo *philo = (t_philo *)arguments;
    pthread_t health_monitor;

    if (pthread_create(&(health_monitor), NULL, &health_check, philo))
        return NULL;
    while (philo->args->state != dead || (philo->args->nb_of_must_eat &&
            philo->eat_cycles < philo->args->nb_of_must_eat))
    {
        eating(philo);
        print_status(philo, "\tis sleeping\n", philo->id, timestamp(philo));
	    usleep(philo->args->time_to_sleep);
        print_status(philo, "\tis thinking\n", philo->id, timestamp(philo));
        philo->eat_cycles++;
    }
    return NULL;
}

int    simulation_loop(t_philo *philo, t_args args, t_mutex mutex)
{
    int i;

	i = 1;
    while (i < (args.nb_of_philo + 1))
    {
        philo[i].start_time = get_time();
        philo[i].eating_time = get_time();
   		if (pthread_create(&(philo[i].tid), NULL, &philo_simulation, &philo[i]))
        	return (-1);
        i++;
    }
    i = 1;
    while (i < (args.nb_of_philo + 1))
    {
        pthread_join(philo[i].tid, NULL);
        i++;
    }
    pthread_mutex_destroy(&mutex.write_lock);
    i = 0;
    while (i < args.nb_of_philo)
    {
        pthread_mutex_destroy(&mutex.forks[i]);
        i++;
    }
    return (0);
}

int		initialize_philo(t_philo *philo, t_args *args, t_mutex *mutex)
{
	int i;

	i = 0;
	if (pthread_mutex_init(&mutex->write_lock, NULL))
        return (-1);
    mutex->forks = malloc(sizeof(pthread_mutex_t) * args->nb_of_philo);
    if (!mutex->forks)
        return (-1);
    while (i < args->nb_of_philo)
    {
        if (pthread_mutex_init(&mutex->forks[i], NULL))
            return (-1);
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

    print(STD_OUT, "time\tphilo\tstatus\n");
	if (validate_args(&args, argc, argv))
        return (error_sequence("parsing error\n"));
    print_args(args); // REMOVE
    philosophers = malloc(sizeof(t_philo) * (args.nb_of_philo + 1));
    if (!philosophers)
       return (error_sequence("malloc failure\n"));
    if (initialize_philo(philosophers, &args, &mutex) ||
        simulation_loop(philosophers, args, mutex))
    {
        free(philosophers);
        return (error_sequence("simulation failure\n"));
    }
    free(philosophers);
    return (0);
}
