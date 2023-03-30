/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:13:56 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/30 13:48:01 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_died(t_philosopher *philosopher, time_t last_meal)
{
	time_t current_time;

	current_time = ft_get_time() - last_meal;
	if (current_time >= philosopher->time_to_die / 1000)
	{
		ft_print_status(philosopher, "died");
		return (0);
	}
	return (1);
}

int ft_check_death(t_philosopher *philosophers, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_lock(&philosophers[i].eat);
		if (!ft_died())
		i++;
	}
	return (1);
}

void *ft_checker(t_philosopher *philosophers, int nb, int end_condition)
{
	while (1)
	{
		if ()
	}
}

void	ft_more_philosophers(t_data *data)
{
	t_philosopher *philosophers;

	philosophers = ft_init_philosophers(data);
	if (!philosophers)
		return ;
	ft_checker(philosophers, data->nb_of_philosophers, data->end_condition);
	free(philosophers);
}