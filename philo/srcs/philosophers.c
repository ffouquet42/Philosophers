/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:33:40 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/20 18:03:46 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	printf("\n\n\n"); // dev
	
	if (argc == 5 || argc == 6)
	{
		if (ft_check_argv(argv))
			return (printf("ARGV ERROR\n"), 0); // *
		else
			ft_setup(argv);
	}
	else
		printf("Incorrect number of arguments\n");

	printf("\n\n\n"); // dev

	return (0);
}
