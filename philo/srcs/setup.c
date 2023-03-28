/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:44:40 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/28 08:49:08 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_data	*ft_setup_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nb_of_philosophers = ft_atoi_long(argv[1]);
	data->time_to_die = ft_atoi_long(argv[2]) * 1000;
	data->time_to_eat = ft_atoi_long(argv[3]) * 1000;
	data->time_to_sleep = ft_atoi_long(argv[4]) * 1000;
	if (argv[5]) // si 0 on fait quoi ?
	{
		data->must_eat = ft_atoi_long(argv[5]);
		data->end_condition = 1;
	}
	else
	{
		data->must_eat = 0;
		data->end_condition = 0;
	}
	return (data);
}

int	ft_check_setup_data(t_data *data)
{
	if (!data)
		return (1);
	else if (data->nb_of_philosophers <= 0)
		return (printf("No philosopher detected\n"), 1);
	return (0);
}

void	ft_setup(char **argv)
{
	t_data			*data;
	// t_philosopher	*philosopher;

	data = ft_setup_data(argv);
	if (ft_check_setup_data(data))
		return (free(data));
	
	ft_print_data(data); // dev
	free(data); // dev
}


// dev

void ft_print_data(t_data *data)
{
	printf("nb : %li\n", data->nb_of_philosophers);
	printf("die : %li\n", data->time_to_die);
	printf("eat : %li\n", data->time_to_eat);
	printf("sleep : %li\n", data->time_to_sleep);
	printf("must eat : %li\n", data->must_eat);
	printf("end cond : %i\n", data->end_condition);
}

// creer fonction double_free pour free data + philo si besoin de 2 free
// {
//		free(x);
//		free(x);
// }