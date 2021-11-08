# philosophers

## Info

42 Cursus - philosophers: this project is a training to multi-threads/multi-process programming.

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

[philo](https://github.com/izenynn/philosophers/tree/main/philo): multi threads and mutex.

[philo_bonus](https://github.com/izenynn/philosophers/tree/main/philo_bonus): multi processes and semaphores.

##

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/it-works-why.svg)](https://forthebadge.com)
