/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:43:49 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/09 13:28:26 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	check_int_max_and_zero(char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (res > INT_MAX)
		return (printf("Be careful to not exceed the int max\n"), 1);
	if (res == 0)
		return (printf("Argv can't be equal to 0\n"), 1);
	return (0);
}

int	check_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (printf("Argv must be positive numbers / digit only\n"), 1);
		i++;
	}
	return (0);
}

int	parsing_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_only_digit(argv[i]) || check_int_max_and_zero(argv[i]))
			return (1);
		i++;
	}
	return (0);
}