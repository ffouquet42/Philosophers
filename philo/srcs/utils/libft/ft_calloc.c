/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:25:35 by fllanet           #+#    #+#             */
/*   Updated: 2023/05/31 04:04:07 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb && ((total_size / nmemb) != size))
		return (NULL);
	tab = malloc(total_size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, total_size);
	return (tab);
}
