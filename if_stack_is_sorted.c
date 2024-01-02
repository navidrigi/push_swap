/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_stack_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:53:22 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:53:24 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_stack_is_sorted(t_list *list)
{
	while (list->next)
	{
		if (list->number > list->next->number)
			return (0);
		list = list->next;
	}
	return (1);
}
