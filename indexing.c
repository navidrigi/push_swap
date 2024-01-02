/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:51:46 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:51:46 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	indexing_process(t_list *list, int size)
// {
// 	t_list	*ptr;
// 	int		array[size];
// 	int		i;

// 	i = 0;
// 	ptr = list;
// 	while (ptr)
// 	{
// 		array[i] = ptr->number;
// 		i++;
// 		ptr = ptr->next;
// 	}
// 	sort_array(array, size);
// 	indexing(list, array, size);
// }

// void	indexing(t_list *list, int *array, int size)
// {
// 	int		i;
// 	t_list	*ptr;

// 	i = 0;
// 	ptr = list;
// 	while (i < size)
// 	{
// 		ptr = list;
// 		while (ptr)
// 		{
// 			if (ptr->number == array[i])
// 			{
// 				ptr->index = i + 1;
// 				break;
// 			}
// 			ptr = ptr->next;
// 		}
// 		i++;
// 	}
// }

// void	sort_array(int *array, int size)
// {
// 	int	i;
// 	int	j;
// 	int	temp;

// 	i = 1;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size - i)
// 		{
// 			if (array[j] > array[j+1])
// 			{
// 				temp = array[j];
// 				array[j] = array[j+1];
// 				array[j+1] = temp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	indexing_process(t_list *stack_a, int stack_size)
{
	t_list	*ptr;
	t_list	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->number == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->number > value && ptr->index == 0)
			{
				value = ptr->number;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
