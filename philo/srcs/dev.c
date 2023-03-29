/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:24:05 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/29 14:24:21 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void ft_print_data(t_data *data)
{
	printf("nb : %li\n", data->nb_of_philosophers);
	printf("die : %li\n", data->time_to_die);
	printf("eat : %li\n", data->time_to_eat);
	printf("sleep : %li\n", data->time_to_sleep);
	printf("must eat : %li\n", data->must_eat);
	printf("end cond : %i\n", data->end_condition);
}