/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:19:31 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 15:29:43 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_state(time_t last_meal, t_philo *philo)
{
	time_t	now;

	now = ft_get_time() - last_meal;
	if (now >= philo->time_to_die / 1000)
	{
		ft_print_status(philo, "died");
		return (0);
	}
	return (1);
}

int	ft_runner(t_philo *philo, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_lock(&philo[i].eating);
		if (ft_state(philo[i].last_meal_time, &philo[i]) == 0)
		{
			pthread_mutex_unlock(&philo[i].eating);
			pthread_mutex_lock(&philo->data->death);
			philo->data->is_alive = 0;
			pthread_mutex_unlock(&philo->data->death);
			return (0);
		}
		pthread_mutex_unlock(&philo[i].eating);
		i++;
	}
	return (1);
}

int	ft_check_end(t_philo *philo, int res, int count)
{
	if (res == count)
	{
		pthread_mutex_lock(&philo->data->end);
		philo->data->must_eat = -1;
		pthread_mutex_unlock(&philo->data->end);
		return (0);
	}
	return (1);
}

int	ft_everyone_ate(t_philo *philo, int count)
{
	int	i;
	int	res;
	int	round;
	int	meals;

	i = 0;
	res = 0;
	pthread_mutex_lock(&philo[i].meal);
	round = philo[i].nb_of_meals;
	pthread_mutex_unlock(&philo[i].meal);
	meals = round;
	while (i < count)
	{
		if (round == philo->data->must_eat)
		{
			if (meals == round)
				res++;
			pthread_mutex_lock(&philo[i].meal);
			meals = philo[i].nb_of_meals;
			pthread_mutex_unlock(&philo[i].meal);
		}
		i++;
	}
	return (ft_check_end(philo, res, count));
}

void	*ft_manager(t_philo *philo, int count, int mode)
{
	while (1)
	{
		if (ft_runner(philo, count) == 0)
			return (NULL);
		if (mode == 1)
		{
			if (ft_everyone_ate(philo, count) == 0)
				return (NULL);
		}
		ft_wait(1000);
	}
	return (NULL);
}