/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:59:28 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/30 18:16:44 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	ft_atoi_long(char *str)
{
	int		i;
	long	res;
	
	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

time_t	ft_get_time(void) // !
{
	struct timeval	time;
	time_t 			current;

	gettimeofday(&time, NULL);
	current = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (current);
}