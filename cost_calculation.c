/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:57:04 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:57:04 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	list_a_cost(t_list **list1, t_list **list2)
// {
// 	int		size_a;
// 	int		ctr;
// 	t_list	*ptr;

// 	size_a = ft_lstsize(*list1);
// 	ptr = *list2;
// 	while (ptr)
// 	{
// 		if (ptr->target_pos <= size_a / 2)
// 			ctr = ptr->target_pos;
// 		else
// 			ctr = -(size_a - ptr->target_pos);
// 		ptr->cost_a = ctr;
// 		ptr = ptr->next;
// 	}
// }

// void	list_b_cost(t_list **list)
// {
// 	int		ctr;
// 	int		size_b;
// 	t_list	*ptr;

// 	size_b = ft_lstsize(*list);
// 	ptr = *list;
// 	while (ptr)
// 	{
// 		if (ptr->position <= size_b / 2)
// 			ctr = ptr->position;
// 		else
// 			ctr = -(size_b - ptr->position);
// 		ptr->cost_b = ctr;
// 		ptr = ptr->next;
// 	}
// }

void	get_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_lstsize(tmp_a);
	size_b = ft_lstsize(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	moving_least_cost(t_list **list1, t_list **list2)
{
	int		cost_a;
	int		cost_b;
	int		least_cost;
	t_list	*ptr;

	least_cost = INT_MAX;
	ptr = *list2;
	while (ptr)
	{
		if (abss(ptr->cost_a) + abss(ptr->cost_b) < abss(least_cost))
		{
			least_cost = abss(ptr->cost_a) + abss(ptr->cost_b);
			cost_a = ptr->cost_a;
			cost_b = ptr->cost_b;
		}
		ptr = ptr->next;
	}
	final_moves(list1, list2, cost_a, cost_b);
}

int	abss(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
