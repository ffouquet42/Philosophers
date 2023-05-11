/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:58:28 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/11 13:42:26 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*loop(void *ptr)
{
	t_philo *philo;
	printf("111\n");
	philo = ptr;
	if (philo->data_struct->nb_of_philo == 1)
		return (one_philo(philo), NULL);
	return (NULL);
}

int	threads_manager(t_data *data, t_philo *philo)
{
	int	i;
	printf("000\n");
	i = 0;
	while (i < data->nb_of_philo)
	{
		printf("001\n");
		pthread_create(&philo[i].philo_thread, NULL, &loop, &philo[i]);
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
	if (threads_manager(data, philo))
		return (free_structs(data, philo), 1);
	return (free_structs(data, philo), 0);
}