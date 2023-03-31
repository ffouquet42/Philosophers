/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:13:56 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 18:54:14 by fllanet          ###   ########.fr       */
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
			if (ft_even_take_fork(philo) == 0)
				break ;
		}
		else
		{
			if (ft_odd_take_fork(philo) == 0)
				break ;	
		}
		if (ft_eat(philo) == 0)
			break ;
		if (ft_sleep(philo) == 0)
			break ;
	}
	return (NULL);
}

void	ft_mutex_fork(t_philo *philo, int nb)
{
	int i;

	i = 0;
	while (i < nb)
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

void	ft_link_forks(t_philo *philo, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		if (i == nb - 1)
		{
			philo[i].right_fork = philo[0].left_fork;
			break ;
		}
		philo[i].right_fork = philo[i + 1].left_fork;
		i++;
	}
}

void	ft_init_thread(t_philo *philo, int nb)
{
	int i;

	i = 0;
	while (i < nb)
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
	ft_mutex_fork(philo, count);
	ft_link_forks(philo, count);
	ft_init_thread(philo, count);
	return (philo);
}