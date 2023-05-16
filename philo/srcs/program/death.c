/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:14 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/16 16:28:56 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	check_death(t_data *data) // OK DIFF
{
	pthread_mutex_lock(&data->check_death);
	if (!data->is_dead)
	{
		pthread_mutex_unlock(&data->check_death);
		return (0);
	}
	pthread_mutex_unlock(&data->check_death);
	return (1);
}

void	death_verification_loop(t_philo *philo, t_data *data) // OK
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

void	philo_died(t_philo *philo, t_data *data, int i) // OK
{
	pthread_mutex_unlock(&philo->data_struct->check_last_eat);
	pthread_mutex_lock(&philo->data_struct->check_death);
	philo->data_struct->is_dead = 1;
	pthread_mutex_unlock(&philo->data_struct->check_death);
	display(philo + i, data, DEATH);
}