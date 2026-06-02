*This project has been created as part of the 42 curriculum by eyilmaz.*

# Philosophers

## Description

Philosophers is a 42 project about the classic Dining Philosophers Problem.

The goal of the project is to simulate philosophers who eat, sleep and think while sharing forks. Each philosopher runs in a separate thread, and each fork is protected with a mutex. The project focuses on thread management, mutex usage, avoiding data races, avoiding deadlocks and handling time-based simulation rules.

## Instructions

Compile the project with:

```bash
make
```

Run the program with:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

```bash
./philo 5 800 200 200
```

With the optional eating limit:

```bash
./philo 5 800 200 200 7
```

Clean object files:

```bash
make clean
```

Remove object files and executable:

```bash
make fclean
```

Recompile:

```bash
make re
```

## Resources

- 42 Philosophers subject
- Linux manual pages:
  - `pthread_create`
  - `pthread_join`
  - `pthread_mutex_init`
  - `pthread_mutex_lock`
  - `pthread_mutex_unlock`
  - `pthread_mutex_destroy`
  - `gettimeofday`
  - `usleep`
- POSIX threads documentation
- Articles and explanations about the Dining Philosophers Problem

## AI Usage

AI was used as a support tool during the project. It helped with understanding the Dining Philosophers Problem, reviewing thread and mutex logic, discussing possible race conditions and deadlocks, preparing evaluation explanations, and organizing this README file.

The final implementation, debugging, testing and project decisions were handled by the project author.
