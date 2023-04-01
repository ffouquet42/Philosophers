/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:19:31 by fllanet           #+#    #+#             */
/*   Updated: 2023/04/01 13:43:38 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_is_alive(time_t last_meal_time, t_philo *philo)
{
	time_t	death_time;

	death_time = ft_get_time() - last_meal_time;
	if (death_time >= philo->time_to_die / 1000)
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

int	ft_need_more_eat(t_philo *philo, int eat_all, int nb)
{
	if (eat_all == nb)
	{
		pthread_mutex_lock(&philo->data->end);
		philo->data->must_eat = -1;
		pthread_mutex_unlock(&philo->data->end);
		return (0);
	}
	return (1);
}

int	ft_all_ate(t_philo *philo, int nb)
{
	int	i;
	int	eat_all;
	int	eated;
	int	meals;

	i = 0;
	eat_all = 0;
	pthread_mutex_lock(&philo[i].meal);
	eated = philo[i].nb_of_meals;
	pthread_mutex_unlock(&philo[i].meal);
	meals = eated;
	while (i < nb)
	{
		if (eated == philo->data->must_eat)
		{
			if (meals == eated)
				eat_all++;
			pthread_mutex_lock(&philo[i].meal);
			meals = philo[i].nb_of_meals;
			pthread_mutex_unlock(&philo[i].meal);
		}
		i++;
	}
	return (ft_need_more_eat(philo, eat_all, nb));
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