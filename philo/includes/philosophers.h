/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:57:57 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/31 05:15:15 by fllanet          ###   ########.fr       */
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

//**********************************************//
//					DEFINES						//
//**********************************************//

//----------------- actions ----------------//
# define FORK 1
# define DEATH 2
# define EAT 3
# define THINK 4
# define SLEEP 5

//----------------- errors messages ----------------//
# define E_ARG_NB "Incorrect number of arguments\n"
# define E_POS_DIGIT "Argv must be positive numbers / digit only\n"
# define E_INT_MAX "Be careful to not exceed the int max\n"
# define E_NOT_ZERO "Argv can't be equal to 0\n"
# define E_MALLOC "Malloc failed\n"
# define E_MUTEX "Mutex init failed\n"

//**********************************************//
//					STRUCTURES					//
//**********************************************//

//----------------- data struct ----------------//
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
	pthread_mutex_t	display;
	pthread_mutex_t	check_must_eat;
	pthread_mutex_t	check_last_eat;
	pthread_mutex_t	check_death;
}	t_data;

//----------------- philo struct ----------------//
typedef struct s_philo
{
	int				id;
	int				nb_of_meals;
	long			last_eat_time;
	struct s_data	*data;
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
void	threads_manager(t_data *data, t_philo *philo);
void	*loop(void *ptr);

//----------------- one_philo.c ----------------//
void	one_philo(t_philo *philo, t_data *data);

//----------------- death.c ----------------//
void	death_verification_loop(t_philo *philo, t_data *data);
int		check_death(t_data *data);
void	philo_died(t_philo *philo, t_data *data, int i);

//----------------- eat.c ----------------//
int		check_must_eat(t_philo *philo, t_data *data);

//----------------- routine.c ----------------//
void	routine_pt1(t_philo *philo, t_data *data);
void	routine_pt2(t_philo *philo, t_data *data);
void	lock_fork(t_philo *philo, t_data *data);
void	unlock_fork(t_philo *philo, t_data *data);

//**********************************************//
//					UTILS						//
//**********************************************//

//----------------- free.c ----------------//
void	free_data(t_data *data);
void	free_structs(t_data *data, t_philo *philo);

//----------------- time.c ----------------//
long	get_time(void);
void	my_wait(t_philo *philo, t_data *data, long long time_to_sleep);

//----------------- display.c ----------------//
void	display(t_philo *philo, t_data *data, int action);

//**********************************************//
//					LIBFT						//
//**********************************************//

//----------------- ft_calloc.c ----------------//
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

//----------------- ft_atoi.c ----------------//
int		ft_atoi(char *str);

#endif