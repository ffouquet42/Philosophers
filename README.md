# Philosophers

*Version: 10*

## Grade - 96/100

Mandatory Part : 100/100  

## Description

In this project, we will learn the basics of threading a process. We will see how to create threads and we will discover mutexes.

## Overview

Here are the things you need to know if you want to succeed this assignment:  
• One or more philosophers sit at a round table.  
There is a large bowl of spaghetti in the middle of the table.  
• The philosophers alternatively eat, think, or sleep.  
While they are eating, they are not thinking nor sleeping;  
while thinking, they are not eating nor sleeping;  
and, of course, while sleeping, they are not eating nor thinking.  
• There are also forks on the table. There are as many forks as philosophers.  
• Because serving and eating spaghetti with only one fork is very inconvenient, a  
philosopher takes their right and their left forks to eat, one in each hand.  
• When a philosopher has finished eating, they put their forks back on the table and  
start sleeping. Once awake, they start thinking again. The simulation stops when  
a philosopher dies of starvation.  
• Every philosopher needs to eat and should never starve.  
• Philosophers don’t speak with each other.  
• Philosophers don’t know if another philosopher is about to die.  
• No need to say that philosophers should avoid dying!  


## What's in this project

It was realized without the bonuses. All the files are normed following the standard of 42.

This project contains the necessary Philosophers code.

* includes

`*.h` 

* srcs

`*.c` 

* others

`Makefile`  
`Subjects : en + fr`  

## How to use it

Create the executables : `philo`.
```javascript
make
```
Run the program.  
```javascript
./philo NB_OF_PHILO TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP
```

Run the program with number of times each philosopher must eat (optional argument).
```javascript
./philo NB_OF_PHILO TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP MUST_EAT
```

## Testing

This project respects the norm of 42 and has been tested with the norminette.  

This project has been tested with valgrind and contains no leaks or data race.  
All tests return : `All heap blocks were freed -- no leaks are possible`.  
 
## Credit

Project made by [ffouquet42](https://github.com/ffouquet42)