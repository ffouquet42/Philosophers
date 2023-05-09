/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:58:28 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/09 12:35:22 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	setup(char **argv)
{
	t_data	*data;
	t_philo	*philo;
	
	data = init_data(argv);
	if (!data)
		return (printf("Init data failed\n"), 1);
	return (free(data), 0);
}