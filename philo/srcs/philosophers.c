/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:59:24 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/09 09:47:13 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf("Incorrect number of arguments\n"), 1);
	if (parsing_argv(argv))
			return (1);
	return (0);
}