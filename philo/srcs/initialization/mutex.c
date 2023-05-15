/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:11:17 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/15 13:22:00 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->display, NULL) ||
		pthread_mutex_init(&data->check_must_eat, NULL) ||
		pthread_mutex_init(&data->check_last_eat, NULL) ||
		pthread_mutex_init(&data->check_death, NULL))
		return (1);
	return (0);
}