/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:59:24 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 15:33:50 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->death);
	if (philo->data->is_alive == 0)
	{
		pthread_mutex_unlock(&philo->data->death);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->death);
	pthread_mutex_lock(&philo->data->end);
	if (philo->data->must_eat == -1)
	{
		pthread_mutex_unlock(&philo->data->end);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->end);
	pthread_mutex_lock(&philo->data->message);
	printf("%ld %d %s\n", ft_get_time() - philo->data->time, philo->id + 1, str);
	pthread_mutex_unlock(&philo->data->message);
	return (1);
}