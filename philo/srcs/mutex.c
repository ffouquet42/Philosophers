/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:50:36 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/30 19:12:16 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_link_forks(t_philosopher *philosophers)
{
	int	i;

	i = 0;
	while (i < philosophers[0].data->nb_of_philosophers)
	{
		if (i == philosophers[0].data->nb_of_philosophers - 1)
		{
			philosophers[i].left_fork = philosophers[0].right_fork;
			break ;
		}
		philosophers[i].left_fork = philosophers[i + 1].right_fork;
		i++;
	}
}

void	ft_init_mutex(t_philosopher *philosophers)
{
	int i;

	i = 0;
	while (i < philosophers[0].data->nb_of_philosophers)
	{
		philosophers[i].right_fork = malloc(sizeof(pthread_mutex_t));
		if (!philosophers[i].right_fork)
			return ;
		pthread_mutex_init(philosophers[i].right_fork, NULL);
		pthread_mutex_init(&philosophers[i].eat, NULL); // ?
		pthread_mutex_init(&philosophers[i].meal, NULL); // ?
		i++;
	}
}