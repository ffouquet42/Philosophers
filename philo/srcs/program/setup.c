/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:58:28 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/16 12:14:37 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*loop(void *ptr)
{
	t_philo *philo;
	
	philo = ptr;
	if (philo->data_struct->nb_of_philo == 1)
		return (one_philo(philo), NULL);
	if (philo->data_struct->nb_of_philo % 2 != 0)
	{
		if (philo->id == philo->data_struct->nb_of_philo)
			wait(philo, (philo->data_struct->time_to_eat * 1000) * 2);
		else if (philo->id % 2 != 0)
			wait(philo, philo->data_struct->time_to_eat * 1000);
	}
	else if ((philo->data_struct->nb_of_philo % 2 == 0) && (philo->id % 2 != 0))
		wait(philo, philo->data_struct->time_to_eat * 1000);
	while (!check_death(philo) && !check_must_eat(philo - (philo->id - 1)))
		routine(philo);
	return (NULL);
}

int	threads_manager(t_data *data, t_philo *philo)
{
	int	i;
	
	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_create(&philo[i].philo_thread, NULL, &loop, &philo[i]);
		i++;
	}
	i = 0;
	usleep(50);
	death_verification_loop(philo);
	while (i < data->nb_of_philo)
	{
		pthread_join(philo[i].philo_thread, NULL);
		i++;
	}
	return (0);
}

int	setup(char **argv)
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