/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:12:14 by gucamuze          #+#    #+#             */
/*   Updated: 2022/02/20 20:49:44 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_args
{
	int					number_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_meals;
	int					i;
	struct timeval		start_time;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		done_mutex;
	int					done;
	pthread_mutex_t		meals_mutex;
	int					nb_of_full_meals;
}						t_data;

typedef struct s_philos_data
{
	int					philo_n;
	pthread_mutex_t		fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		lml_mutex;
	t_data				*timers;
	struct timeval		last_meal_time;
	int					meals_eaten;
}						t_pdata;

// Setup
t_data					*check_args(int ac, char **av);
int						second_arg_check(t_data *args);
t_pdata					**setup_philos_d(t_data *args);
// utils
void					schlafmutze(long int t_us, t_data *data);
int						atoi_w_return(char *str, int *nb_ptr);
size_t					ft_strlen(const char *str);
// Threads
int						is_done(t_data *data);
int						get_time_ms(struct timeval tv1, struct timeval tv2);
void					philo_output(int mode, t_pdata *philo);
void					*philo_thread(void *ptr);
// supervisor
void					supervisor(t_pdata **philos, t_data *data);

#endif