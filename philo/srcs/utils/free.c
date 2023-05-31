/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:26:26 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/31 05:42:28 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	free_data(t_data *data) // ~
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	free(data->fork);
	pthread_mutex_destroy(&data->display); // &
	pthread_mutex_destroy(&data->check_must_eat);
	pthread_mutex_destroy(&data->check_last_eat);
	pthread_mutex_destroy(&data->check_death);
	free(data);
}

void	free_structs(t_data *data, t_philo *philo) // OK DIFF
{
	free_data(data);
	free(philo);
}
