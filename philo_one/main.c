/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 11:38:02 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/18 15:54:45 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"
#include "structs.h"
#include "threads.h"
#include "parsing.h"
#include "simulation.h"

#include <stdio.h>
#include "print_functions.h"

int counter;

void    print_args(t_simulation_args args)
{
    printf("\t nb of philo = %d\n", args.nb_of_philo);
    printf("\t nb of must eat = %d\n", args.nb_of_must_eat);
    printf("\t time to eat = %d\n", args.time_to_eat);
    printf("\t time to sleep = %d\n", args.time_to_sleep);
    printf("\t time to die = %d\n", args.time_to_die);
    printf("\t start time = %ld\n", args.time.tv_sec);
}

// void	*philo_simulation(void *arguments)
// {

// 	t_simulation_args *args = (t_simulation_args *)arguments;

// 	pthread_mutex_lock(&args->mutex.lock_one);
//     printf("\n philo simulation \n");
//     print_args(*args);
//     unsigned long i = 0;
//     counter += 1;
//     if (args)
// 		printf("\n Job %d has started\n", counter);

//     for (i = 0; i < 2; i++)
//         ;

//     printf("\n Job %d has finished\n", counter);


//     printf("timestamp = %ld\n", timestamp(args));

//     pthread_mutex_unlock(&args->mutex.lock_one);

//     return NULL;
// }


void	*philo_simulation(void *arguments)
{
	t_simulation_args *args = (t_simulation_args *)arguments;

    // -> while 'nobody dies' or 'nb of eating rounds'
    //take left fork
    //take right fork
    //eat --> dies if food is not on time
    //sleep
    eating(args);

    return NULL;
}


int		main(int argc, char **argv)
{
    t_simulation_args	args;
    int i;

    i = 1;
    print(STD_OUT, "time\tphilo\tstatus\n");
	if (validate_args(argc, argv) || parse_args(&args, argc, argv) ||
        initialize_philo(&args) || initialize_mutex(&args))
		return -1;
	parse_args(&args, argc, argv);
	gettimeofday(&args.time, NULL);
    while (i < (args.nb_of_philo + 1))
    {
       pthread_join(args.philo[i].tid, NULL);
       i++;
    }
    pthread_mutex_destroy(&args.mutex.eat_lock);
    pthread_mutex_destroy(&args.mutex.left_fork);
    pthread_mutex_destroy(&args.mutex.right_fork);

    return 0;
}



