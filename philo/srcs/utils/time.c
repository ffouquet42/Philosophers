/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:50:04 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/11 14:42:02 by fllanet          ###   ########.fr       */
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

void	wait(t_philo *philo, long long time_to_sleep) // long
{
	long long start_time;
	
	start_time = get_time();
	while (((get_time() - start_time) * 1000) < time_to_sleep
		&& !check_death(philo) && !check_must_eat(philo - (philo->id - 1)))
		usleep(50);
}