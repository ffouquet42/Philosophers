/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:23:20 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/11 13:36:18 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	one_philo(t_philo *philo)
{
	display(philo, FORK);
	pthread_mutex_lock(&philo->data_struct->check_death);
	philo->data_struct->is_dead = 1;
	pthread_mutex_unlock(&philo->data_struct->check_death);
	usleep(philo->data_struct->time_to_die * 1000);
	display(philo, DEATH);
}