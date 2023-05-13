/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:31:32 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/13 11:57:15 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	routine(t_philo *philo) // data
{
	if (!check_death(philo) && !check_must_eat(philo - (philo->id - 1)))
	{
		if (!check_death(philo)) // test avec et sans ces lignes
		{
			// lock fork
			pthread_mutex_lock(&philo->data_struct->check_last_eat);
			philo->last_eat_time = get_time() - philo->data_struct->time;
			pthread_mutex_unlock(&philo->data_struct->check_last_eat);
			display(philo, EAT);
			pthread_mutex_lock(&philo->data_struct->check_must_eat);
			philo->nb_of_meals++;
			pthread_mutex_unlock(&philo->data_struct->check_must_eat);
			wait(philo, philo->data_struct->time_to_eat * 1000);
			// unlock fork
		}
	}
	if (!check_death(philo) && !check_must_eat(philo - (philo->id - 1)))
	{
		if (!check_death(philo)) // test avec et sans ces lignes
		{
			display(philo, SLEEP);
			wait(philo, philo->data_struct->time_to_sleep * 1000);
		}
	}
	if (!check_death(philo) && !check_must_eat(philo - (philo->id - 1)))
	{
		if (!check_death(philo)) // test avec et sans ces lignes
			display(philo, THINK);
	}
	usleep(500);
}

void	lock_fork(t_philo *philo) // data
{
	
}

void	unlock_fork(t_philo *philo) // data
{
	
}