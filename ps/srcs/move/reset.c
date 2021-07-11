/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:19:09 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/07/12 01:20:33 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_move(t_data *data)
{
	data->ma[1]->move = NULL;
	data->ma[1]->n = 0;
	data->mb[1]->move = NULL;
	data->mb[1]->n = 0;
	data->ma[0]->move = NULL;
	data->ma[0]->n = 0;
	data->ma[0]->value = 0;
	data->mb[0]->move = NULL;
	data->mb[0]->n = 0;
	data->mb[0]->value = 0;
}
