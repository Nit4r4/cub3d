/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:48:55 by vferraro          #+#    #+#             */
/*   Updated: 2022/11/17 08:52:26 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <fcntl.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>

/* DEFINE COLORS */
# define PURP "\e[35m"
# define GREEN "\e[32m"
# define RED "\e[31m"
# define WHITE "\e[39m"
# define YELLOW "\033[33m"
# define ORANGE "$(shell tput setaf 208)"
# define RESET "\e[0"
# define BLUE "\033[34m"
# define CYAN "\033[36m"

/* ERRORS MESSAGES */
# define ERR_ARG "\033[31mError : bad number of arguments"

/* ACTIONS MESSAGES */
# define M_MSG "Inclure le message voulu ici"

/* STRUCT */
typedef struct s_cub3d
{
	int				nbr_of_fork;
	int				name;
	int				meals_eaten;
	int				last_meal;
	bool			alive;
	pthread_t		th_philo;
	pthread_mutex_t	fork;
	t_args			*args;
}	t_cub3d;

typedef struct s_args
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meal;
	int				time_to_think;
	int				all_meal_eaten;
	long int		start_time;
	long int		end_time;
	pthread_mutex_t	mutex;
	struct s_philo	*philos;
}	t_args;


/* UTILS */


/* MANDATORY */


/* BONUS (ON Y CROIT) */


#endif
