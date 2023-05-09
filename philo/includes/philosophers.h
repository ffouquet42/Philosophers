/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:57:57 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/09 12:41:03 by fllanet          ###   ########.fr       */
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
	pthread_mutex_t	check_die;
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
int		check_int_max(char *str);


//**********************************************//
//					INITIALIZATION				//
//**********************************************//

//----------------- data.c ----------------//
t_data	*init_data(char **argv);


//**********************************************//
//					PROGRAM						//
//**********************************************//

//----------------- setup.c ----------------//
int		setup(char **argv);


//**********************************************//
//					UTILS						//
//**********************************************//

//----------------- free.c ----------------//


//**********************************************//
//					LIBFT						//
//**********************************************//

//----------------- ft_calloc.c ----------------//
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

//----------------- ft_atoi.c ----------------//
int		ft_atoi_long(char *str);


#endif