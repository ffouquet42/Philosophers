/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:19:31 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 18:56:32 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_is_alive(time_t last_meal_time, t_philo *philo)
{
	time_t	now;

	now = ft_get_time() - last_meal_time;
	if (now >= philo->time_to_die / 1000)
	{
		ft_print_status(philo, "died");
		return (0);
	}
	return (1);
}

int	ft_check_death(t_philo *philo, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_lock(&philo[i].eating);
		if (ft_is_alive(philo[i].last_meal_time, &philo[i]) == 0)
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

int	ft_need_more_eat(t_philo *philo, int res, int nb)
{
	if (res == nb)
	{
		pthread_mutex_lock(&philo->data->end);
		philo->data->must_eat = -1;
		pthread_mutex_unlock(&philo->data->end);
		return (0);
	}
	return (1);
}

int	ft_all_ate(t_philo *philo, int nb) // #
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
	while (i < nb)
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
	return (ft_need_more_eat(philo, res, nb));
}

void	*ft_program(t_philo *philo, int nb, int end_cond)
{
	while (1)
	{
		if (ft_check_death(philo, nb) == 0)
			return (NULL);
		if (end_cond == 1)
		{
			if (ft_all_ate(philo, nb) == 0)
				return (NULL);
		}
		ft_wait(1000);
	}
	return (NULL);
}