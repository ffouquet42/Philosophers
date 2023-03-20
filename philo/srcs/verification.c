/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:58:14 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/20 18:13:39 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_check_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (printf("Argv must be digit only\n"), 1);
		i++;
	}
	return (0);
}

int	ft_check_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_check_only_digit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
