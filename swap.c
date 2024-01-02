/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:44:56 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:45:27 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *list)
{
	int	temp;

	if (list == NULL || list->next == NULL)
		return ;
	temp = list->number;
	list->number = list->next->number;
	list->next->number = temp;
	temp = list->index;
	list->index = list->next->index;
	list->next->index = temp;
}
