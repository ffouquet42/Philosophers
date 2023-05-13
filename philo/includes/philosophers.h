/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:57:57 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/13 11:56:36 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//**********************************************//
//					INCLUDES					//
//**********************************************//

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
//
// # include <string.h>
// # include <stddef.h>


//**********************************************//
//					DEFINES						//
//**********************************************//

# define FORK 1
# define DEATH 2
# define EAT 3
# define THINK 4
# define SLEEP 5


//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_data
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				is_dead;
	long			time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write;
	pthread_mutex_t	check_must_eat;
	pthread_mutex_t	check_last_eat;
	pthread_mutex_t	check_death;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				nb_of_meals;
	long			last_eat_time;
	struct s_data	*data_struct;
	pthread_t		philo_thread;
}	t_philo;


//**********************************************//
//					PROTOTYPES					//
//**********************************************//

//----------------- philosophers.c ----------------//
int		main(int argc, char **argv);


//**********************************************//
//					PARSING						//
//**********************************************//

//----------------- argv.c ----------------//
int		parsing_argv(char **argv);
int		check_only_digit(char *str);
int		check_int_max_and_zero(char *str);


//**********************************************//
//					INITIALIZATION				//
//**********************************************//

//----------------- data.c ----------------//
t_data	*init_data(char **argv);

//----------------- mutex.c ----------------//
int		init_mutex(t_data *data);

//----------------- philo.c ----------------//
t_philo	*init_philo(t_data *data);


//**********************************************//
//					PROGRAM						//
//**********************************************//

//----------------- setup.c ----------------//
int		setup(char **argv);
int		threads_manager(t_data *data, t_philo *philo);
void	*loop(void *ptr);

//----------------- one_philo.c ----------------//
void	one_philo(t_philo *philo);

//----------------- death.c ----------------//
void	death_verification_loop(t_philo *philo);
int		check_death(t_philo *philo);

//----------------- eat.c ----------------//
int		check_must_eat(t_philo *philo);

//----------------- routine.c ----------------//
void	routine(t_philo *philo);
void	lock_fork(t_philo *philo);
void	unlock_fork(t_philo *philo);


//**********************************************//
//					UTILS						//
//**********************************************//

//----------------- free.c ----------------//
void	free_data(t_data *data);
void	free_structs(t_data *data, t_philo *philo);

//----------------- time.c ----------------//
long	get_time(void);
void	wait(t_philo *philo, long long time_to_sleep);

//----------------- display.c ----------------//
void	display(t_philo *philo, int action);


//**********************************************//
//					LIBFT						//
//**********************************************//

//----------------- ft_calloc.c ----------------//
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

//----------------- ft_atoi.c ----------------//
int		ft_atoi(char *str);



// dev
void	print_data(t_data *data);

#endif