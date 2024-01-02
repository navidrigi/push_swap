/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:45:44 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:46:03 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_general(t_list **list1, t_list **list2)
{
	push_to_b_except_3(list1, list2);
	sort_three(list1);
	while (*list2)
	{
		target_positioning(list1, list2);
		get_cost(list1, list2);
		moving_least_cost(list1, list2);
	}
	if (if_stack_is_sorted(*list1) == 0)
		moving_lowest_position_to_top(list1);
}

void	sort_three(t_list **list)
{
	int		highest_indexx;

	if (if_stack_is_sorted(*list))
		return ;
	highest_indexx = highest_index(*list);
	if ((*list)->index == highest_indexx)
	{
		rotate_a(list);
		write (1, "ra\n", 3);
	}
	else if ((*list)->next->index == highest_indexx)
	{
		reverse_rotate_a(list);
		write (1, "rra\n", 4);
	}
	if ((*list)->index > (*list)->next->index)
	{
		swap_a(*list);
		write (1, "sa\n", 3);
	}
}

int	highest_index(t_list *list)
{
	int		index;
	t_list	*ptr;

	index = list->index;
	ptr = list;
	while (ptr)
	{
		if (ptr->index > index)
			index = ptr->index;
		ptr = ptr->next;
	}
	return (index);
}
