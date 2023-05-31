/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:31:32 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/31 03:51:43 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	routine_pt1(t_philo *philo, t_data *data) // OK
{
	if (!check_death(data) && !check_must_eat(philo - (philo->id - 1), data))
	{
		if (!check_death(data))
		{
			lock_fork(philo, philo->data_struct);
			pthread_mutex_lock(&philo->data_struct->check_last_eat);
			philo->last_eat_time = get_time() - philo->data_struct->time;
			pthread_mutex_unlock(&philo->data_struct->check_last_eat);
			display(philo, data, EAT);
			pthread_mutex_lock(&philo->data_struct->check_must_eat);
			philo->nb_of_meals++;
			pthread_mutex_unlock(&philo->data_struct->check_must_eat);
			my_wait(philo, data, philo->data_struct->time_to_eat * 1000);
			unlock_fork(philo, philo->data_struct);
		}
	}
	routine_pt2(philo, data);
}

void	routine_pt2(t_philo *philo, t_data *data) // OK
{
	if (!check_death(data) && !check_must_eat(philo - (philo->id - 1), data))
	{
		if (!check_death(data))
		{
			display(philo, data, SLEEP);
			my_wait(philo, data, philo->data_struct->time_to_sleep * 1000);
		}
	}
	if (!check_death(data) && !check_must_eat(philo - (philo->id - 1), data))
	{
		if (!check_death(data))
			display(philo, data, THINK);
	}
	usleep(500);
}

void	lock_fork(t_philo *philo, t_data *data) // OK
{
	if (philo->id == 1)
	{
		pthread_mutex_lock(&data->fork[data->nb_of_philo - 1]);
		pthread_mutex_lock(&data->fork[philo->id - 1]);
		display(philo, data, FORK);
		display(philo, data, FORK);
		return ;
	}
	pthread_mutex_lock(&data->fork[philo->id - 1]);
	pthread_mutex_lock(&data->fork[philo->id - 2]);
	display(philo, data, FORK);
	display(philo, data, FORK);
}

void	unlock_fork(t_philo *philo, t_data *data) // OK
{
	if (philo->id == 1)
	{
		pthread_mutex_unlock(&data->fork[data->nb_of_philo - 1]);
		pthread_mutex_unlock(&data->fork[philo->id - 1]);
		return ;
	}
	pthread_mutex_unlock(&data->fork[philo->id - 1]);
	pthread_mutex_unlock(&data->fork[philo->id - 2]);
}