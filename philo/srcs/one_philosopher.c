/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:30:17 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/29 14:20:16 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_eat_alone(void *ptr)
{
	t_philosopher *philosopher;

	philosopher = ptr;
	printf("%ld %d has taken a fork\n", ft_get_time()
		- philosopher->data->time, philosopher->id);
	usleep(philosopher->data->time_to_die);
	printf("%ld %d died\n", ft_get_time() - philosopher->data->time,
		philosopher->id);
	pthread_exit(NULL);
}

void	ft_one_philosopher(t_data *data, t_philosopher *philosopher)
{
	philosopher = malloc(sizeof(t_philosopher));
	if (!philosopher)
		return ;
	philosopher->id = 1;
	philosopher->meals = 0;
	philosopher->data = data;
	philosopher->last_meal = ft_get_time();
	pthread_create(&philosopher->thread, NULL, &ft_eat_alone, philosopher);
	pthread_join(philosopher->thread, NULL);
	free(philosopher);
}