/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:50:04 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/31 05:47:05 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

long	get_time(void)
{
	struct timeval	time;
	long			current;

	gettimeofday(&time, NULL);
	current = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (current);
}

void	my_wait(t_philo *philo, t_data *data, long long time_to_sleep)
{
	long long	start_time;

	start_time = get_time();
	while (((get_time() - start_time) * 1000) < time_to_sleep
		&& !check_death(data) && !check_must_eat(philo - (philo->id - 1), data))
		usleep(50);
}
