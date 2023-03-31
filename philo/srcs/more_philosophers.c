/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:13:56 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 15:20:03 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_eat_together(void *ptr)
{
	t_philo *philo;

	philo = ptr;
	if (philo->id % 2 == 0)
		ft_wait(philo->time_to_eat / 2);
	while (1)
	{
		if (philo->id % 2 == 0)
		{
			if (ft_even_fork(philo) == 0)
				break ;
		}
		else
		{
			if (ft_odd_fork(philo) == 0)
				break ;	
		}
		if (ft_eating(philo) == 0)
			break ;
		if (ft_sleeping(philo) == 0)
			break ;
	}
	return (NULL);
}

void	ft_init_thread(t_philo *philo, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		pthread_create(&philo[i].thread, NULL, &ft_eat_together, &philo[i]);
		i++;
	}
}

t_philo	*ft_init_philo(t_data *data)
{
	int i;
	int count;
	t_philo *philo;

	i = 0;
	count = data->nb_of_philosophers;
	philo = malloc(sizeof(t_philo) * count);
	if (!philo)
		return (NULL);
	while (i < count)
	{
		philo[i].id = i;
		philo[i].nb_of_meals = 0;
		philo[i].data = data;
		philo[i].time_to_die = data->time_to_die;
		philo[i].time_to_eat = data->time_to_eat;
		philo[i].time_to_sleep = data->time_to_sleep;
		philo[i].last_meal_time = ft_get_time();
		i++;
	}
	ft_init_mutex(philo, count);
	ft_connect_mutex(philo, count);
	ft_init_thread(philo, count);
	return (philo);
}