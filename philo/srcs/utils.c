/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:59:28 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 15:33:03 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	ft_atoi_long(char *str)
{
	int		i;
	long	res;
	
	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

time_t	ft_get_time(void) // !
{
	struct timeval	time;
	time_t 			current;

	gettimeofday(&time, NULL);
	current = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (current);
}

void	ft_clean_exit(char *str, void *ptr) // !
{
	printf("%s", str);
	free(ptr);
	exit(EXIT_FAILURE);
}

void	ft_waitforme(t_philo *philo, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		pthread_join(philo[i].thread, NULL);
}

void	ft_destroy(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philosophers)
	{
		pthread_mutex_destroy(philo[i].left_fork);
		free(philo[i].left_fork);
		pthread_mutex_destroy(&philo[i].eating);
		pthread_mutex_destroy(&philo[i].meal);
		i++;
	}
	free(philo);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->message);
	pthread_mutex_destroy(&data->end);
	free(data);
}