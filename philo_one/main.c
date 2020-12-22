/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 11:38:02 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 15:30:39 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"
#include "structs.h"
#include "threads.h"
#include "parsing.h"
#include "eating.h"
#include "print_functions.h"
#include "time_calc.h"
#include "error.h"

#include <stdlib.h>

#include "stdio.h"

int         g_philo_amount;

void	*philo_simulation(void *arguments)
{
	t_philo *philosophers = (t_philo *)arguments;

    // -> while 'nobody dies' or 'nb of eating rounds'
    //take left fork
    //take right fork
    //eat --> dies if food is not on time
    //sleep

    eating(philosophers);

    return NULL;
}



int    simulation_loop(t_philo *philo, t_args args, t_mutex mutex)
{
    int i;
    long long time;

	i = 1;
	time = get_time();
    while (i < (args.nb_of_philo + 1))
    {
        philo[i].start_time = time;
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
    pthread_mutex_destroy(&mutex.eat_lock);
    pthread_mutex_destroy(&mutex.left_fork);
    pthread_mutex_destroy(&mutex.right_fork);
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
