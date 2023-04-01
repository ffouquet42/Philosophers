/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:19:12 by fllanet           #+#    #+#             */
/*   Updated: 2023/04/01 13:51:30 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_wait(time_t rest)
{
	struct timeval	tv;
	struct timeval	start;
	long int		need;

	gettimeofday(&start, NULL);
	need = 0;
	rest /= 1000;
	while (need < rest)
	{
		gettimeofday(&tv, NULL);
		need = (tv.tv_sec - start.tv_sec) * 1000
			+ (tv.tv_usec - start.tv_usec) / 1000;
		usleep(30);
	}
	return (1);
}

int	ft_even_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (ft_print_status(philo, "has taken a fork") == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	pthread_mutex_lock(philo->right_fork);
	if (ft_print_status(philo, "has taken a fork") == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	return (1);
}

int	ft_odd_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (ft_print_status(philo, "has taken a fork") == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	pthread_mutex_lock(philo->left_fork);
	if (ft_print_status(philo, "has taken a fork") == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	return (1);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philo->eating);
	if (ft_print_status(philo, "is eating") == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	ft_wait(philo->time_to_eat);
	pthread_mutex_lock(&philo->meal);
	philo->nb_of_meals += 1;
	pthread_mutex_unlock(&philo->meal);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_print_status(philo, "is sleeping") == 0)
		return (0);
	ft_wait(philo->time_to_sleep);
	if (ft_print_status(philo, "is thinking") == 0)
		return (0);
	ft_wait((philo->time_to_eat - philo->time_to_sleep)
		* ((philo->time_to_eat - philo->time_to_sleep) > 0));
	ft_wait(1500);
	return (1);
}
