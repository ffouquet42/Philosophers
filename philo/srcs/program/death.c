/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:14 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/31 05:48:15 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	check_death(t_data *data)
{
	pthread_mutex_lock(&data->check_death);
	if (!data->is_dead)
		return (pthread_mutex_unlock(&data->check_death), 0);
	return (pthread_mutex_unlock(&data->check_death), 1);
}

void	death_verification_loop(t_philo *philo, t_data *data)
{
	int	i;

	while (!check_death(data))
	{
		i = 0;
		while (i < data->nb_of_philo)
		{
			pthread_mutex_lock(&data->check_last_eat);
			if ((get_time() - data->time - philo[i].last_eat_time)
				>= data->time_to_die)
				return (philo_died(philo, data, i));
			else
				pthread_mutex_unlock(&data->check_last_eat);
			i++;
		}
	}
}

void	philo_died(t_philo *philo, t_data *data, int i)
{
	pthread_mutex_unlock(&philo->data->check_last_eat);
	pthread_mutex_lock(&philo->data->check_death);
	philo->data->is_dead = 1;
	pthread_mutex_unlock(&philo->data->check_death);
	display(philo + i, data, DEATH);
}
