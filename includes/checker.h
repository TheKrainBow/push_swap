/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:53:07 by magostin          #+#    #+#             */
/*   Updated: 2021/10/20 15:28:12 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifdef BONUS
#  include <sys/types.h>
#  include <sys/stat.h>
#  include <fcntl.h>
# endif

# include "common.h"
# include "color.h"
# include "../libft/includes/libft.h"
# define PROMPT "\033[1;36m\033[AChecker>: \033[1;37m"

void		sort_stack(t_stack *a);
t_chunk		*chunk_stack(t_data *data, t_stack *a, int n, int print);
int			check_b_insert(t_data *data, int index);
void		revers_moves(t_data *data);
int			exec_moves(t_data *data, t_move *ma, t_move *mb, int move);
int			ind(int i, char a);
void		generate_moves(t_data *data);
void		best_move_for_b(t_data *data);
void		best_move_for_a(t_data *data, int n);
void		clear_move(t_data *data);
void		sort_chunk(t_data *data, int n);
void		push_swap(t_data *data, int print);

#endif
