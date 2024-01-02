/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:50:18 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:50:18 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	positioning(t_list **list)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = *list;
	while (ptr)
	{
		ptr->position = i;
		i++;
		ptr = ptr->next;
	}
}

void	target_positioning(t_list **list1, t_list **list2)
{
	int		target_pos;
	t_list	*ptr2;

	ptr2 = *list2;
	positioning(list1);
	positioning(list2);
	target_pos = 0;
	while (ptr2)
	{
		target_pos = target_position(list1, ptr2->index, INT_MAX, target_pos);
		ptr2->target_pos = target_pos;
		ptr2 = ptr2->next;
	}
}

// finding target position based on position of closest higher index

int	target_position(t_list **list1, int index, int target_indx, int target_pos)
{
	t_list	*ptr1;

	ptr1 = *list1;
	while (ptr1)
	{
		if (ptr1->index > index && ptr1->index < target_indx)
		{
			target_indx = ptr1->index;
			target_pos = ptr1->position;
		}
		ptr1 = ptr1->next;
	}
	if (target_indx != INT_MAX)
		return (target_pos);
	ptr1 = *list1;
	while (ptr1)
	{
		if (ptr1->index < target_indx)
		{
			target_indx = ptr1->index;
			target_pos = ptr1->position;
		}
		ptr1 = ptr1->next;
	}
	return (target_pos);
}

// if there is no higher index in the target list

int	lowest_index_position(t_list *list)
{
	int		smallest_index;
	int		position;
	t_list	*ptr;

	smallest_index = INT_MAX;
	position = 0;
	ptr = list;
	while (ptr)
	{
		if (ptr->index < smallest_index)
			smallest_index = ptr->index;
		ptr = ptr->next;
	}
	ptr = list;
	while (ptr)
	{
		if (ptr->index == smallest_index)
		{
			position = ptr->position;
			break ;
		}
		ptr = ptr->next;
	}
	return (position);
}

// int	finding_position_with_index(t_list *list, int closest_index)
// {
// 	int		position;
// 	t_list	*ptr;

// 	ptr = list;
// 	while (ptr)
// 	{
// 		if (ptr->index == closest_index)
// 		{
// 			position = ptr->position;
// 			break;
// 		}
// 		ptr = ptr->next;
// 	}
// 	return (position);
// }
