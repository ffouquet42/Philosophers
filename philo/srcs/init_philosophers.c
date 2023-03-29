/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:19:31 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/29 16:49:43 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_philosopher *ft_init_philosophers(t_data *data)
{
	t_philosopher	*philosophers;
	int				i;

	philosophers = malloc(sizeof(t_philosopher) * data->nb_of_philosophers);
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < data->nb_of_philosophers)
	{
		philosophers[i].id = i;
		philosophers[i].nb_of_meals = 0;
		philosophers[i].data = data;
		philosophers[i].time_to_die = data->time_to_die;
		philosophers[i].timt_to_eat = data->time_to_eat;
		philosophers[i].time_to_sleep = data->time_to_sleep;
		philosophers[i].last_meal_time = ft_get_time();
		i++;
	}
	return (philosophers);
}