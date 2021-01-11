<p align="center">
  <img src="https://github.com/rbakker96/images/blob/master/codam_logo.png">
</p>

# philosophers
***The aim of this project is to make you code a program that uses threads and synchronize them with different techniques.***

---

### Project summary
> 4th ring Codam project

In this project, you will learn the basics of threading a process and how to work on the same memory space. You will learn how to make threads. You will discover the mutex, semaphore and shared memory.

---

### Technical considerations
> The project needs to comply with the following rules/functionalities.

- This project is to be coded in C, following the Norm. Any leak, crash, undefined behavior or norm error means 0 to the project.
- A number of philosophers are sitting at a round table doing one of three things: eating, thinking or sleeping.
- While eating, they are not thinking or sleeping, while sleeping, they are not eating or thinking and of course, while thinking, they are not eating or sleeping.
- The philosophers sit at a circular table with a large bowl of spaghetti in the center.
- There are some forks on the table.
- As spaghetti is difficult to serve and eat with a single fork, it is assumed that a philosopher must eat with two forks, one for each hand.
- The philosophers must never be starving.
- Every philosopher needs to eat.
- Philosophers don’t speak with each other.
- Philosophers don’t know when another philosopher is about to die.
- Each time a philosopher has finished eating, he will drop his forks and start sleeping.
- When a philosopher is done sleeping, he will start thinking.
- The simulation stops when a philosopher dies.
- Each program should have the same options: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
  - number_of_philosophers: is the number of philosophers and also the number of forks
  - time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal or the beginning of the simulation, it dies
  - time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.
  - time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.
  - number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.
- Each philosopher should be given a number from 1 to ’number_of_philosophers’.
- Philosopher number 1 is next to philosopher number ’number_of_philosophers’. Any other philosopher with number N is seated between philosopher N - 1 and philosopher N + 1
- Any change of status of a philosopher must be written as follows (with X replaced with the philosopher number and timestamp_in_ms the current timestamp in milliseconds)
  - timestamp_in_ms X has taken a fork
  - timestamp_in_ms X is eating
  - timestamp_in_ms X is sleeping
  - timestamp_in_ms X is thinking
  - timestamp_in_ms X died
- The status printed should not be scrambled or intertwined with another philosopher’s status.
- You can’t have more than 10 ms between the death of a philosopher and when it will print its death.
- Again, philosophers should avoid to die!


---

### philo_one
> <a href="https://github.com/rbakker96/philosophers/tree/master/philo_one" target="_blank">Folder</a><br>

> In this version the non common rules will be:

- One fork between each philosopher, therefore there will be a fork at the right and at the left of each philosopher.
- To avoid philosophers duplicating forks, you should protect the forks state with a mutex for each of them.
- Each philosopher should be a thread.


### philo_two
> <a href="https://github.com/rbakker96/philosophers/tree/master/philo_two" target="_blank">Folder</a><br>

> In this version the non common rules will be:

- All the forks are in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.
- Each philosopher should be a thread.


### philo_three
> <a href="https://github.com/rbakker96/philosophers/tree/master/philo_three" target="_blank">Folder</a><br>

> In this version the non common rules will be:

- All the forks are in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.
- Each philosopher should be a process and the main process should not be a philosopher.

---

### Usage
> Run the following commands in the terminal

```shell
$ https://github.com/rbakker96/philosophers.git philosophers
$ cd philosophers
-> To test for example philo_one
$ cd philo_one
$ make
$ ./philo_one 5 800 200 200 5
```

---

### Used resources
> Most noteworthy resources used during this project

- <a href="https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/" target="_blank">Mutex lock for Linux Thread Synchronization</a>
- <a href="https://www.geeksforgeeks.org/semaphores-in-process-synchronization/" target="_blank">Semaphores in Process Synchronization</a>
- <a href="https://github.com/angrave/SystemProgramming/wiki/Synchronization,-Part-2:-Counting-Semaphores" target="_blank">Synchronization, Part 2: Counting Semaphores</a>
- <a href="https://www.mkssoftware.com/docs/man3/pthread_create.3.asp#:~:text=If%20thread%20is%20not%20NULL,new%20thread%20throughout%20its%20lifetime." target="_blank">pthread_create() man page</a>


