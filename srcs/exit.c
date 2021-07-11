/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:06:26 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/07/12 01:27:47 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_exit(t_data *data, int free_power, void *ptr)
{
	if (ptr)
		free(ptr);
	printf("Error\n");
	free_data(data, free_power);
	exit(1);
}
