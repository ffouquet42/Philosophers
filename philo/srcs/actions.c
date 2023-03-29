/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:19:12 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/29 17:29:21 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_wait(time_t to_wait)
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