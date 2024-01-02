/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:47:44 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:48:12 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **list)
{
	t_list	*last;
	t_list	*ptr;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	ptr = *list;
	last = ft_lstlast(*list);
	while (ptr->next->next)
		ptr = ptr->next;
	ptr->next = NULL;
	last->next = *list;
	*list = last;
}

void	reverse_rotate_b(t_list **list)
{
	t_list	*last;
	t_list	*ptr;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	ptr = *list;
	last = ft_lstlast(*list);
	while (ptr->next->next)
		ptr = ptr->next;
	ptr->next = NULL;
	last->next = *list;
	*list = last;
}
