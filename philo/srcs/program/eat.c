/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:17 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/31 05:33:19 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	check_must_eat(t_philo *philo, t_data *data) // ~
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->check_must_eat);
	if (!data->must_eat)
		return (pthread_mutex_unlock(&data->check_must_eat), 0);
	while (i < data->nb_of_philo)
	{
		if (philo[i].nb_of_meals < data->must_eat)
			return (pthread_mutex_unlock(&data->check_must_eat), 0);
		i++;
	}
	return (pthread_mutex_unlock(&data->check_must_eat), 1);
}
