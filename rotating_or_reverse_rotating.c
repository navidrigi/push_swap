/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_or_reverse_rotating.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:46:18 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:46:22 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moving_lowest_position_to_top(t_list **list1)
{
	int	lowest_position;
	int	list_size;

	positioning(list1);
	lowest_position = lowest_index_position(*list1);
	list_size = ft_lstsize(*list1);
	if (lowest_position <= list_size / 2)
	{
		while (lowest_position > 0)
		{
			rotate_a(list1);
			write (1, "ra\n", 3);
			lowest_position--;
		}
	}
	else
	{
		while (lowest_position < list_size)
		{
			reverse_rotate_a(list1);
			write (1, "rra\n", 4);
			lowest_position++;
		}
	}
}
