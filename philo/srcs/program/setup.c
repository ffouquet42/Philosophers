/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:58:28 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/31 05:41:27 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*loop(void *ptr) // +
{
	t_philo	*philo;
	t_data	*data;

	philo = ptr;
	data = philo->data;
	if (data->nb_of_philo == 1)
		return (one_philo(philo, data), NULL);
	if (data->nb_of_philo % 2 != 0)
	{
		if (philo->id == data->nb_of_philo)
			my_wait(philo, data, (data->time_to_eat * 1000) * 2);
		else if (philo->id % 2 != 0)
			my_wait(philo, data, data->time_to_eat * 1000);
	}
	else if ((data->nb_of_philo % 2 == 0) && (philo->id % 2 != 0))
		my_wait(philo, data, data->time_to_eat * 1000);
	while (!check_death(data) && !check_must_eat(philo - (philo->id - 1), data))
		routine_pt1(philo, data);
	return (NULL);
}

void	threads_manager(t_data *data, t_philo *philo) // ~
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_create(&philo[i].philo_thread, NULL, &loop, &philo[i]); // ?
		i++;
	}
	i = 0;
	usleep(50); // ?
	death_verification_loop(philo, data);
	while (i < data->nb_of_philo)
	{
		pthread_join(philo[i].philo_thread, NULL);
		i++;
	}
	return ;
}

int	setup(char **argv) // ~
{
	t_data	*data;
	t_philo	*philo;

	data = init_data(argv);
	if (!data)
		return (1);
	philo = init_philo(data);
	if (!philo)
		return (free_data(data), 1);
	threads_manager(data, philo);
	return (free_structs(data, philo), 0);
}
