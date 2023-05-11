/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:09:19 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/11 15:03:14 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

t_data	*init_data(char **argv)
{
	t_data *data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (printf("Data init : malloc failed\n"), NULL);
	data->nb_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->time = get_time();
	data->is_dead = 0;
	data->must_eat = 0;
	if (argv[5])
		data->must_eat = ft_atoi(argv[5]);
	data->fork = ft_calloc(sizeof(pthread_mutex_t), data->nb_of_philo);
	if (!data->fork)
		return (printf("Mutex malloc failed\n"), free(data), NULL);
	if (init_mutex(data))
		return (printf("Mutex init failed\n"), free_data(data), NULL);
	return (data);
}