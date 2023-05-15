/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:26:04 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/15 13:21:37 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	display(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->data_struct->display);
	if (!check_death(philo) && !check_must_eat(philo - (philo->id - 1)))
	{
		if (action == FORK)
			printf("%ld %i has taken a fork\n", get_time()
			- philo->data_struct->time, philo->id);
		else if (action == EAT)
			printf("%ld %i is eating\n", get_time()
			- philo->data_struct->time, philo->id);
		else if (action == THINK)
			printf("%ld %i is thinking\n", get_time()
			- philo->data_struct->time, philo->id);
		else if (action == SLEEP)
			printf("%ld %i is sleeping\n", get_time()
			- philo->data_struct->time, philo->id);
	}
	else if (action == DEATH && !check_must_eat(philo - (philo->id - 1)))
		printf("%ld %i died\n", get_time()
			- philo->data_struct->time, philo->id);
	pthread_mutex_unlock(&philo->data_struct->display);
}