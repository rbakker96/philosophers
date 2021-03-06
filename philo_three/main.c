/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 11:38:02 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/09 15:26:28 by roybakker     ########   odam.nl         */
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

int		simulation_loop(t_philo *philo, t_args args)
{
	int pid;
	int status;
	int i;

	i = 1;
	while (i < (args.nb_of_philo + 1))
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			philo_simulation(&philo[i]);
			exit(0);
		}
		i++;
	}
	while (1)
	{
		if (waitpid(-1, &status, 0) <= 0)
			break ;
	}
	return (0);
}

int		initialize_philo(t_philo *philo, t_args *args, t_semaphore *semaphore)
{
	int i;

	i = 1;
	while (i < (args->nb_of_philo + 1))
	{
		philo[i].semaphore = semaphore;
		philo[i].args = args;
		philo[i].eat_cycles = 0;
		philo[i].id = i;
		i++;
	}
	return (0);
}

int		initialize_semaphores(t_semaphore *semaphore, int nb_of_philo)
{
	semaphore->state = succes;
	semaphore->forks = sem_open("/forks", O_CREAT, 0644, nb_of_philo);
	semaphore->write_lock = sem_open("/write_lock", O_CREAT, 0644, 1);
	semaphore->health_lock = sem_open("/health_lock", O_CREAT, 0644, 1);
	sem_unlink("/forks");
	sem_unlink("/write_lock");
	sem_unlink("/health_lock");
	if (semaphore->forks == SEM_FAILED || semaphore->write_lock == SEM_FAILED ||
		semaphore->health_lock == SEM_FAILED)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_args		args;
	t_semaphore	semaphore;
	t_philo		*philosophers;

	write(STD_OUT, "time\tphilo\tstatus\n", 18);
	if (validate_args(&args, argc, argv))
		return (error_sequence("parsing error\n", 0));
	philosophers = malloc(sizeof(t_philo) * (args.nb_of_philo + 1));
	if (!philosophers)
		return (error_sequence("malloc fail\n", 0));
	if (initialize_semaphores(&semaphore, args.nb_of_philo) ||
		initialize_philo(philosophers, &args, &semaphore) ||
		simulation_loop(philosophers, args))
		return (error_sequence("simulation fail\n", philosophers));
	free(philosophers);
	return (0);
}
