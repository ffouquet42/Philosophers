/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:31:45 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/20 17:59:17 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H


// ---------- INCLUDES ---------- //
# include <stdio.h>


// ---------- STRUCTURES ---------- //

// ---------- PROTOTYPES ---------- //

// ---------- philosophers.c ---------- //
int	main(int argc, char **argv);

// ---------- verification.c ---------- //
int	ft_check_argv(char **argv);

// ---------- setup.c ---------- //
void	ft_setup(char **argv);

#endif