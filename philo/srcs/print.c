/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:59:24 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 12:09:26 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_print_status(t_philosopher *philosopher, char *str)
{
	pthread_mutex_lock(&philosopher->data->death);
	if (!philosopher->data->is_alive)
	{
		pthread_mutex_unlock(&philosopher->data->death);
		return (0);
	}
	pthread_mutex_unlock(&philosopher->data->death);
	pthread_mutex_lock(&philosopher->data->end);
	if (philosopher->data->must_eat == -1)
	{
		pthread_mutex_unlock(&philosopher->data->end);
		return (0);
	}
	pthread_mutex_unlock(&philosopher->data->end);
	pthread_mutex_lock(&philosopher->data->msg);
	printf("%ld %d %s\n", ft_get_time() - philosopher->data->time, philosopher->id + 1, str); // +1 ?
	pthread_mutex_unlock(&philosopher->data->msg);
	return (1);
}