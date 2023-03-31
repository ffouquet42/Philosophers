/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:50:36 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 15:03:00 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_mutex(t_philo *philo, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		philo[i].left_fork = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].left_fork)
			return ;
		pthread_mutex_init(philo[i].left_fork, NULL);
		pthread_mutex_init(&philo[i].eating, NULL);
		pthread_mutex_init(&philo[i].meal, NULL);
		i++;
	}
}

void	ft_connect_mutex(t_philo *philo, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (i == count - 1)
		{
			philo[i].right_fork = philo[0].left_fork;
			break ;
		}
		philo[i].right_fork = philo[i + 1].left_fork;
		i++;
	}
}