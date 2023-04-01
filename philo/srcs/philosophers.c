/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:33:40 by fllanet           #+#    #+#             */
/*   Updated: 2023/04/01 13:51:16 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (ft_check_argv(argv))
			return (1);
		else
			ft_setup(argv);
	}
	else
		return (printf("Incorrect number of arguments\n"), 1);
	return (0);
}
