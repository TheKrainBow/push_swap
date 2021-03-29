/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:53:07 by magostin          #+#    #+#             */
/*   Updated: 2021/03/28 16:38:09 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct		s_stack
{
	int				*stack;
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
	t_stack			*sorted_a;
	t_chunk			*chunked_a;
	int				first;
	int				last;
	int				print;
	int				n_ope;
}					t_data;

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

#endif