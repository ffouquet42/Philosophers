/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:26:04 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/11 13:37:26 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	display(t_philo *philo, int action)
{
	if (action == FORK)
		printf("display FORK\n");
	else if (action == DEATH)
		printf("display DEATH\n");
}