/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:49:41 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/10/05 19:25:11 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include "struct.h"

t_data		*init_data(void);
void		parsing(t_data *data);
char		**create_args(char **av, int ac);
void		load_stack_arg(t_data *data, char **args);
void		generate_random_stack(t_data *data, int push_swap);

void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);

void		print_stacks(t_data *data, int reset);
void		print_stack(t_stack *a, int arrow);
int			top_stack(t_stack *a);
void		sort_stack(t_stack *a);
t_stack		*copy(t_stack *a);

void		free_stack(t_stack *a);
void		free_data(t_data *data, int free_power);
void		ft_exit(t_data *data, int free_power, void *ptr);

int			checker(t_stack *a, int correct_size, int print, int color);

void		ft_swap(int *a, int *b);

#endif
