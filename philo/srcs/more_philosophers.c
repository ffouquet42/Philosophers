/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:13:56 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/29 16:51:28 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_more_philosophers(t_data *data)
{
	t_philosopher *philosophers;

	philosophers = ft_init_philosophers(data);
	if (!philosophers)
		return ;
	free(philosophers);
}