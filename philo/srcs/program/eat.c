/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:17 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/11 15:06:32 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	check_must_eat(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->data_struct->check_must_eat);
	if (!philo->data_struct->must_eat)
	{
		pthread_mutex_unlock(&philo->data_struct->check_must_eat);
		return (0);
	}
	while (i < philo->data_struct->nb_of_philo)
	{
		if (philo[i].nb_of_meals < philo->data_struct->must_eat)
		{
			pthread_mutex_unlock(&philo->data_struct->check_must_eat);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&philo->data_struct->check_must_eat);
	return (1);
}