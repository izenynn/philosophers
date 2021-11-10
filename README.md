# philosophers

## Info

42 Cursus - philosophers: this project is a training to multi-threads/multi-process programming.

- Status: finished
- Result: 125%
- Observations: (null)

## The philosophers problem

The classic dining philosopher problem.

This problem states that N philosophers seated around a circular table with one fork between each pair of philosophers. A philosopher may eat if he can pick up the two forks adjacent to him. One fork may be picked up by any one of its adjacent followers but not both. 

Each time a philosopher finish eating, they will drop drop their forks and start sleeping. Once they have finished sleeping, the will start thinking and waiting to eat.

Simulation stops when a philosopher dies.

Every philosopher needs to eat and they should never starve.

Philosophers do not speak with each other.

Philosophers do not know when another philospher is about to die.

And of course, philosophers should avoid dying.

## Solutions

[philo](https://github.com/izenynn/philosophers/tree/main/philo): philosophers with threads and mutex.

[philo_bonus](https://github.com/izenynn/philosophers/tree/main/philo_bonus): philosophers with processes and semaphore.

## How to use

Clone the repo

```sh
git clone https://github.com/izenynn/libft.git
```
Go to `philo` or `philo_bonus` folder and run `make`

```sh
cd ./philo && make
```
```sh
cd ./philo_bonus && make
```

*Makefile rules: `all`, `clean`, `fclean`, `re`.*

Usage

```sh
./philo [N PHILOS] [DIE TIME] [EAT TIME] [SLEEP TIME] (OPT)[PHILO EAT N TIMES]
```

- last argument is optional.

- `philo_bonus` takes the same arguments as `philo`.

Example

```sh
./philo 4 800 200 200
```

```sh
./philo_bonus 10 410 200 200 7
```

##

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/it-works-why.svg)](https://forthebadge.com)
