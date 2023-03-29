/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:31:45 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/29 14:29:28 by fllanet          ###   ########.fr       */
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
	int				is_dead;
	time_t			time;
	pthread_mutex_t	end;
	pthread_mutex_t	msg;
	pthread_mutex_t	death;
}	t_data;

typedef struct s_philosopher
{
	int				id;
	int				meals;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	time_t			last_meal;
	t_data 			*data;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	meal;
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
void	ft_double_free(t_data *data, t_philosopher *philosopher);
time_t	ft_get_time(void);

// ---------- print.c ---------- //

// ---------- one_philosopher.c ---------- //
void	ft_one_philosopher(t_data *data);
t_philosopher *ft_setup_one_philosopher(t_data *data);
void	*ft_eat_alone(void *ptr);

// DEV
void ft_print_data(t_data *data);

#endif