/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:31:45 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 18:56:26 by fllanet          ###   ########.fr       */
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
	int				is_alive;
	int				end_condition;
	time_t			time;
	pthread_mutex_t	end;
	pthread_mutex_t	message;
	pthread_mutex_t	death;
}			t_data;

typedef struct s_philo
{
	int				id;
	int				nb_of_meals;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	time_t			last_meal_time;
	t_data 			*data;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	eating;
	pthread_mutex_t	meal;
}			t_philo;

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
int		ft_print_status(t_philo *philo, char *str);

// ---------- utils.c ---------- //
long	ft_atoi_long(char *str);
time_t	ft_get_time(void);
void	ft_exit_no_philo(char *str, void *ptr);
void	ft_loop_threads(t_philo *philo, int nb);
void	ft_destroy(t_philo *philo, t_data *data);

// ---------- one_philosopher.c ---------- //
void	ft_one_philosopher(t_data *data, t_philo *philo);
void	*ft_eat_alone(void *ptr);

// ---------- more_philosophers.c ---------- //
t_philo	*ft_init_philo(t_data *data);
void	ft_init_thread(t_philo *philo, int nb);
void	*ft_eat_together(void *ptr);
void	ft_mutex_fork(t_philo *philo, int nb);
void	ft_link_forks(t_philo *philo, int nb);

// ---------- program.c ---------- //
void	*ft_program(t_philo *philo, int nb, int end_cond);
int		ft_check_death(t_philo *philo, int nb);
int		ft_is_alive(time_t last_meal_time, t_philo *philo);
int		ft_all_ate(t_philo *philo, int nb);
int		ft_need_more_eat(t_philo *philo, int res, int nb); // #

// ---------- actions.c ---------- //
int		ft_wait(time_t rest);
int		ft_even_take_fork(t_philo *philo);
int		ft_odd_take_fork(t_philo *philo);
int		ft_eat(t_philo *philo);
int		ft_sleep(t_philo *philo);

#endif