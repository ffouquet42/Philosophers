/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:19:12 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/30 19:37:42 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_wait(time_t to_wait)
{
	struct timeval	actual_time;
	struct timeval	beginning;
	long int		current_time;

	gettimeofday(&beginning, NULL);
	current_time = 0;
	to_wait /= 1000;
	while (current_time < to_wait)
	{
		gettimeofday(&actual_time, NULL);
		current_time = (actual_time.tv_sec - beginning.tv_sec) * 1000 + (actual_time.tv_usec - beginning.tv_usec) / 1000;
		usleep(30);
	}
	return (1);
}

int	ft_even_take_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	if (!ft_print_status(philosopher, "has taken a fork"))
	{
		pthread_mutex_unlock(philosopher->right_fork);
		return (0);
	}
	pthread_mutex_lock(philosopher->left_fork);
	if (!ft_print_status(philosopher, "has taken a fork"))
	{
		pthread_mutex_unlock(philosopher->left_fork);
		pthread_mutex_unlock(philosopher->right_fork);
		return (0);
	}
	return (1);
}

int	ft_odd_take_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	if (!ft_print_status(philosopher, "has taken a fork"))
	{
		pthread_mutex_unlock(philosopher->left_fork);
		return (0);
	}
	pthread_mutex_lock(philosopher->right_fork);
	if (!ft_print_status(philosopher, "has taken a fork"))
	{
		pthread_mutex_unlock(philosopher->right_fork);
		pthread_mutex_unlock(philosopher->left_fork);
		return (0);
	}
	return (1);
}

int	ft_eat(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->eat);
	philosopher->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philosopher->eat);
	if (!ft_print_status(philosopher, "is eating"))
	{
		pthread_mutex_unlock(philosopher->right_fork);
		pthread_mutex_unlock(philosopher->left_fork);
		return (0);
	}
	ft_wait(philosopher->time_to_eat);
	pthread_mutex_lock(&philosopher->meal);
	philosopher->nb_of_meals += 1;
	pthread_mutex_unlock(&philosopher->meal);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
	return (1);
}

int	ft_sleep(t_philosopher *philosopher)
{
	if (!ft_print_status(philosopher, "is sleeping"))
		return (0);
	ft_wait(philosopher->time_to_sleep);
	if (!ft_print_status(philosopher, "is thinking"))
		return (0);
	ft_wait((philosopher->time_to_eat - philosopher->time_to_sleep)
		* ((philosopher->time_to_eat - philosopher->time_to_sleep) > 0)); // >0?
	ft_wait(1500);
	return (1);
}