/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:19:09 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/11/05 00:46:12 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_move(t_data *data)
{
	data->ma_f->n_right = 0;
	data->mb->n_right = 0;
	data->ma_f->n_left = 0;
	data->ma_f->value = 0;
	data->mb->n_left = 0;
	data->mb->value = 0;
}
