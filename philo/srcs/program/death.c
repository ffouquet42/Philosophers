/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:14 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/16 12:12:47 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data_struct->check_death);
	if (!philo->data_struct->is_dead)
	{
		pthread_mutex_unlock(&philo->data_struct->check_death);
		return (0);
	}
	pthread_mutex_unlock(&philo->data_struct->check_death);
	return (1);
}

void	death_verification_loop(t_philo *philo) // -> int
{
	int	i;
	
	while (!check_death(philo))
	{
		i = 0;
		while (i < philo->data_struct->nb_of_philo)
		{
			pthread_mutex_lock(&philo->data_struct->check_last_eat);
			if ((get_time() - philo->data_struct->time -
				philo[i].last_eat_time) >= philo->data_struct->time_to_die)
			{
				pthread_mutex_unlock(&philo->data_struct->check_last_eat);
				pthread_mutex_lock(&philo->data_struct->check_death);
				philo->data_struct->is_dead = 1;
				pthread_mutex_unlock(&philo->data_struct->check_death);
				display(philo + i, DEATH);
				return ;
			}
			else
				pthread_mutex_unlock(&philo->data_struct->check_last_eat);
			i++;
		}
	}
}