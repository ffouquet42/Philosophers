/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:59:24 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/09 13:37:59 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf("Incorrect number of arguments\n"), 1);
	if (parsing_argv(argv))
			return (1);
	if (setup(argv))
		return (1);
	return (0);
}



// dev

void print_data(t_data *data)
{
	printf("nb of philo   : %i\n", data->nb_of_philo);
	printf("time to die   : %i\n", data->time_to_die);
	printf("time to eat   : %i\n", data->time_to_eat);
	printf("time to sleep : %i\n", data->time_to_sleep);
	printf("must eat      : %i\n", data->must_eat);
	printf("is dead       : %i\n", data->is_dead);
	printf("time          : %li\n", data->time);
}