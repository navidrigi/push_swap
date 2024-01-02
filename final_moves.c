/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:56:23 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:56:23 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_moves(t_list **list1, t_list **list2, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		rotate_both(list1, list2, &cost_a, &cost_b);
	if (cost_a < 0 && cost_b < 0)
		rrotate_both(list1, list2, &cost_a, &cost_b);
	rotate_a_with_costing(list1, &cost_a);
	rotate_b_with_costing(list2, &cost_b);
	push_to_a(list1, list2);
}

void	rotate_both(t_list **list1, t_list **list2, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rotate_a(list1);
		rotate_b(list2);
		write (1, "rr\n", 3);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rrotate_both(t_list **list1, t_list **list2, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		reverse_rotate_a(list1);
		reverse_rotate_b(list2);
		write (1, "rrr\n", 4);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	rotate_a_with_costing(t_list **list1, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			rotate_a(list1);
			write (1, "ra\n", 3);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			reverse_rotate_a(list1);
			write (1, "rra\n", 4);
			(*cost_a)++;
		}
	}
}

void	rotate_b_with_costing(t_list **list2, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rotate_b(list2);
			write (1, "rb\n", 3);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			reverse_rotate_b(list2);
			write (1, "rrb\n", 4);
			(*cost_b)++;
		}
	}
}
