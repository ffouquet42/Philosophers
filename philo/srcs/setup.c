/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:44:40 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 15:31:26 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_data	*ft_setup_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nb_of_philosophers = ft_atoi_long(argv[1]);
	if (data->nb_of_philosophers < 1)
		ft_clean_exit("No one's arround the table\n", data);
	data->time = (time_t)ft_get_time();
	data->time_to_die = ft_atoi_long(argv[2]) * 1000;
	data->time_to_eat = ft_atoi_long(argv[3]) * 1000;
	data->time_to_sleep = ft_atoi_long(argv[4]) * 1000;
	data->is_alive = 1;
	data->end_condition = 0;
	pthread_mutex_init(&data->end, NULL);
	pthread_mutex_init(&data->message, NULL);
	pthread_mutex_init(&data->death, NULL);
	if (argv[5])
	{
		data->must_eat = ft_atoi_long(argv[5]);
		data->end_condition = 1;
	}
	else
		data->must_eat = 0;
	return (data);
}

void	ft_setup(char **argv)
{
	t_data	*data;
	t_philo *philo;

	philo = NULL;
	data = ft_setup_data(argv);
	if (data->nb_of_philosophers == 1)
		ft_one_philosopher(data, philo);
	else
	{
		philo = ft_init_philo(data);
		ft_manager(philo, data->nb_of_philosophers, data->end_condition);
		ft_waitforme(philo, data->nb_of_philosophers);
		ft_destroy(philo, data);
	}
}