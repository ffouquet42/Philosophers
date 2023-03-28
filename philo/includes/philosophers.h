/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:31:45 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/28 08:49:32 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H


// ---------- INCLUDES ---------- //
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>

// ---------- STRUCTURES ---------- //

typedef struct s_data
{
	long	nb_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	must_eat;
	int		end_condition; // *
}	t_data;

typedef struct s_philosopher
{
	int	id;
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

// ---------- print.c ---------- //


// DEV
void ft_print_data(t_data *data);

#endif