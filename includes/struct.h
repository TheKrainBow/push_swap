/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:42:49 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/11/05 02:22:25 by krain            ###   ########.fr       */
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
	struct s_move	*ma;
	struct s_move	*mb;
	struct s_move	*ma_f;
	struct s_move	*ma_l;
	struct s_move	*mb_f;
	struct s_move	*mb_l;
	t_stack			*sorted_a;
	t_chunk			*chunked_a;
	int				first;
	int				last;
	int				print;
	int				n_ope;
	int				n_chunk;
	t_flags			*flags;
}					t_data;

typedef struct s_move
{
	int				n_right;
	int				n_left;
	int				value;
}					t_move;

#endif
