/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:19:31 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/30 19:08:43 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_thread_philosopher(void *ptr)
{
	t_philosopher *philosopher;

	philosopher = ptr;
	if (philosopher->id % 2 == 0)
		ft_wait(philosopher->time_to_eat / 2);
	while (1)
	{
		if (philosopher->id % 2 == 0)
		{
			if (!ft_even_take_fork(philosopher))
				break ;
		}
		else
		{
			if (!ft_odd_take_fork(philosopher))
				break ;
		}
		if (!ft_eat(philosopher))
			break ;
		if (!ft_sleep(philosopher))
			break ;
	}
	pthread_exit(NULL);
}

void	ft_run_thread(t_philosopher *philosophers)
{
	int i;

	i = 0;
	while (i < philosophers[0].data->nb_of_philosophers)
	{
		pthread_create(&philosophers[i].thread, NULL, &ft_thread_philosopher, &philosophers[i]);
		i++;
	}
}

t_philosopher *ft_init_philosophers(t_data *data)
{
	t_philosopher	*philosophers;
	int				i;

	philosophers = malloc(sizeof(t_philosopher) * data->nb_of_philosophers);
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < data->nb_of_philosophers)
	{
		philosophers[i].id = i;
		philosophers[i].nb_of_meals = 0;
		philosophers[i].time_to_die = data->time_to_die;
		philosophers[i].time_to_eat = data->time_to_eat;
		philosophers[i].time_to_sleep = data->time_to_sleep;
		philosophers[i].last_meal_time = ft_get_time();
		philosophers[i].data = data;
		i++;
	}
	ft_init_mutex(philosophers);
	ft_link_forks(philosophers);
	ft_run_thread(philosophers);
	return (philosophers);
}