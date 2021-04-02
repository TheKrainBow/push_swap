/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:53:07 by magostin          #+#    #+#             */
/*   Updated: 2021/04/02 10:37:49 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifdef BONUS
#  include <sys/types.h>
#  include <sys/stat.h>
#  include <fcntl.h>
# endif

# include "color.h"
# include "../libft/includes/libft.h"

typedef struct		s_stack
{
	int				*stack;
	int				max;
	int				min;
	int				size;
}					t_stack;

typedef struct		s_chunk
{
	int				min;
	int				max;
}					t_chunk;

typedef struct		s_data
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
}					t_data;

typedef struct		s_move
{
	int				n;
	int				value;
	void			(*move)(t_data *);
}					t_move;

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
void		print_stack(t_stack *a);

#endif