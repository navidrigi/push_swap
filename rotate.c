/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:46:34 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:47:32 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*ptr;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	first = *list;
	second = (*list)->next;
	ptr = ft_lstlast(*list);
	ptr->next = first;
	first->next = NULL;
	*list = second;
}

void	rotate_b(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*ptr;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	first = *list;
	second = (*list)->next;
	ptr = ft_lstlast(*list);
	ptr->next = first;
	first->next = NULL;
	*list = second;
}
