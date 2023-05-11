/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:14 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/11 14:59:46 by fllanet          ###   ########.fr       */
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