/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:31:45 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/30 17:42:19 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// ---------- INCLUDES ---------- //
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

// ---------- STRUCTURES ---------- //

typedef struct s_data
{
	long			nb_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat;
	int				end_condition;
	int				is_alive;
	time_t			time;
	pthread_mutex_t	end;	// *
	pthread_mutex_t	msg;	// *
	pthread_mutex_t	death;	// *
}	t_data;

typedef struct s_philosopher
{
	int				id;
	int				nb_of_meals;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	time_t			last_meal_time;
	t_data 			*data;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;	// *
	pthread_mutex_t	*left_fork;		// *
	pthread_mutex_t	eat;			// *
	pthread_mutex_t	meal;			// *
}	t_philosopher;


// ---------- PROTOTYPES ---------- //

// ---------- philosophers.c ---------- //
int		main(int argc, char **argv);

// ---------- verification.c ---------- //
int		ft_check_argv(char **argv);
int		ft_check_only_digit(char *str);
int		ft_check_int_max(char *str);

// ---------- setup.c ---------- //
void	ft_setup(char **argv);
t_data	*ft_setup_data(char **argv);
int		ft_check_setup_data(t_data *data);

// ---------- utils.c ---------- //
long	ft_atoi_long(char *str);
time_t	ft_get_time(void);

// ---------- print.c ---------- //
int	ft_print_status(t_philosopher *philosopher, char *str);

// ---------- one_philosopher.c ---------- //
void	ft_one_philosopher(t_data *data);
t_philosopher *ft_setup_one_philosopher(t_data *data);
void	*ft_eat_alone(void *ptr);

// ---------- more_philosophers.c ---------- //
void	ft_more_philosophers(t_data *data);
void	*ft_checker(t_philosopher *philosophers, int nb, int end_condition);
int		ft_check_death(t_philosopher *philosophers, int nb);
int		ft_died(t_philosopher *philosopher, time_t last_meal);
void 	ft_destroy(t_philosopher *philosophers, t_data *data);
void 	ft_waitforme(t_philosopher *philosophers, int nb);
int		ft_everyone_ate(t_philosopher *philosophers, int nb);
int		ft_check_end(t_philosopher *philosophers, int res, int nb);

// ---------- init_philosophers.c ---------- //
t_philosopher *ft_init_philosophers(t_data *data);
void	ft_run_thread(t_philosopher *philosophers);
void	*ft_thread_philosopher(void *ptr);

// ---------- mutex.c ---------- //
void	ft_init_mutex(t_philosopher *philosophers);
void	ft_link_forks(t_philosopher *philosophers);

// ---------- actions.c ---------- //
int	ft_wait(time_t time);
int	ft_even_take_fork(t_philosopher *philosopher);
int	ft_odd_take_fork(t_philosopher *philosopher);
int	ft_eat(t_philosopher *philosopher);
int	ft_sleep(t_philosopher *philosopher);

#endif