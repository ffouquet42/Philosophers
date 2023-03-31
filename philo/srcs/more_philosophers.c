/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:13:56 by fllanet           #+#    #+#             */
/*   Updated: 2023/03/31 12:42:04 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_died(t_philosopher *philosopher, time_t last_meal)
{
	printf("##### ft_died #####\n");
	time_t current_time;

	current_time = ft_get_time() - last_meal;
	if (current_time >= philosopher->time_to_die / 1000)
	{
		ft_print_status(philosopher, "died");
		printf("##### ft_died return 0 #####\n");
		return (0);
	}
	printf("##### ft_died return 1 #####\n");
	return (1);
}

int ft_check_death(t_philosopher *philosophers, int nb)
{
	int i;
	printf("##### ft_checkdeath #####\n");
	i = 0;
	while (i < nb)
	{
		pthread_mutex_lock(&philosophers[i].eat);
		if (!ft_died(&philosophers[i], philosophers[i].last_meal_time))
		{
			printf("##### ft_checkdeath -> ft_died = 0 #####\n");
			pthread_mutex_unlock(&philosophers[i].eat);
			pthread_mutex_lock(&philosophers->data->death);
			philosophers->data->is_alive = 0;
			pthread_mutex_unlock(&philosophers->data->death);
			printf("##### ft_checkdeath return 0 #####\n");
			return (0);
		}
		pthread_mutex_unlock(&philosophers[i].eat);
		i++;
	}
	printf("##### ft_checkdeath return 1 #####\n");
	return (1);
}

int	ft_check_end(t_philosopher *philosophers, int res, int nb)
{
	if (res == nb)
	{
		pthread_mutex_lock(&philosophers->data->end);
		philosophers->data->must_eat = -1;
		printf("##### -1 #####\n");
		pthread_mutex_unlock(&philosophers->data->end);
		return (0);
	}
	return (1);
}

int	ft_everyone_ate(t_philosopher *philosophers, int nb)
{
	int i;
	int res;
	int round;
	int meals;

	i = 0;
	res = 0;
	pthread_mutex_lock(&philosophers[i].meal);
	round = philosophers[i].nb_of_meals;
	pthread_mutex_unlock(&philosophers[i].meal);
	meals = round;
	while (i < nb)
	{
		if (round == philosophers->data->must_eat)
		{
			if (meals == round)
				res++;
			pthread_mutex_lock(&philosophers[i].meal);
			meals = philosophers[i].nb_of_meals;
			pthread_mutex_unlock(&philosophers[i].meal);
			
		}
		i++;
	}
	printf("##### Appel check end #####\n");
	return (ft_check_end(philosophers, res, nb));
}

// regrouper les if return NULL
void *ft_checker(t_philosopher *philosophers, int nb, int end_condition)
{
	while (1)
	{
		printf("##### WHILE ft_checker #####\n");
		if (ft_check_death(philosophers, nb) == 0);
		{
			printf("##### 001 #####\n");
			return (NULL);
		}
		printf("##### 000 #####\n");
		if (end_condition == 1)
		{
			printf("##### End condition == 1 #####\n");
			if (!ft_everyone_ate(philosophers, nb));
				return (NULL);
		}
		ft_wait(1000);
	}
	return (NULL);
}

// supp la fonction et mettre dans more_philosophers
void ft_waitforme(t_philosopher *philosophers, int nb)
{
	int i;

	i = -1;
	while (++i < nb)
		pthread_join(philosophers[i].thread, NULL);
}

// a bouger dans utils
void ft_destroy(t_philosopher *philosophers, t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_of_philosophers)
	{
		pthread_mutex_destroy(philosophers[i].right_fork);
		free(philosophers[i].right_fork);
		pthread_mutex_destroy(&philosophers[i].eat);
		pthread_mutex_destroy(&philosophers[i].meal);
		i++;
	}
	free(philosophers);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->msg);
	pthread_mutex_destroy(&data->end);
	free(data);
}

void	ft_more_philosophers(t_data *data)
{
	t_philosopher *philosophers;

	philosophers = ft_init_philosophers(data);
	if (!philosophers)
		return ;
	// printf("##### Avant ft_checker #####\n");
	ft_checker(philosophers, data->nb_of_philosophers, data->end_condition);
	// printf("##### Apres ft_checker #####\n");
	ft_waitforme(philosophers, data->nb_of_philosophers);
	ft_destroy(philosophers, data);
	free(philosophers); // pas utile
}