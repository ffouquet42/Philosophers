/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:35:47 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/31 05:25:18 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

t_philo	*init_philo(t_data *data) // ~
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
		philo[i].data = data;
		i++;
	}
	return (philo);
}
