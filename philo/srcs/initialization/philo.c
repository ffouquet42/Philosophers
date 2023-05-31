/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:35:47 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/31 04:06:21 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

t_philo	*init_philo(t_data *data) // OK
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = ft_calloc(sizeof(t_philo), data->nb_of_philo);
	if (!philo)
		return (printf(E_MALLOC), NULL);
	while (i < data->nb_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].nb_of_meals = 0;
		philo[i].last_eat_time = 0;
		philo[i].data_struct = data;
		i++;
	}
	return (philo);
}
