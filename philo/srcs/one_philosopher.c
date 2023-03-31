/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:30:17 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 14:53:48 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_eat_alone(void *ptr)
{
	t_philo *philo;

	philo = ptr;
	printf("%ld %d has taken a fork\n", ft_get_time()
		- philo->data->time, philo->id);
	usleep(philo->data->time_to_die);
	printf("%ld %d died\n", ft_get_time() - philo->data->time,
		philo->id);
	return (NULL);
}

void	ft_one_philosopher(t_data *data, t_philo *philo)
{
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return ;
	philo->id = 1;
	philo->nb_of_meals = 0;
	philo->data = data;
	philo->last_meal_time = ft_get_time();
	pthread_create(&philo->thread, NULL, &ft_eat_alone, philo);
	pthread_join(philo->thread, NULL);
	free(philo);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->message);
	free(data);
}