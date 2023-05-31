/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:23:20 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/31 05:48:00 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	one_philo(t_philo *philo, t_data *data)
{
	display(philo, data, FORK);
	pthread_mutex_lock(&data->check_death);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->check_death);
	usleep(data->time_to_die * 1000);
	display(philo, data, DEATH);
}
