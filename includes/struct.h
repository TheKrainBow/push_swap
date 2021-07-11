/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:42:49 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/07/12 01:29:56 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_stack
{
	int				*stack;
	int				max;
	int				min;
	int				size;
}					t_stack;

typedef struct s_chunk
{
	int				min;
	int				max;
}					t_chunk;

typedef struct s_flags
{
	int				random;
	int				color;
	int				visualize;
	char			**args;
}					t_flags;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	struct s_move	*ma[2];
	struct s_move	*mb[2];
	t_stack			*sorted_a;
	t_chunk			*chunked_a;
	int				first;
	int				print;
	int				n_ope;
	int				n_chunk;
	t_flags			*flags;
}					t_data;

typedef struct s_move
{
	int				n;
	int				value;
	void			(*move)(t_data *);
}					t_move;

#endif
