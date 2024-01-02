/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:48:30 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:48:51 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*populating_list_1st_time(int argc, char **argv)
{
	int			i;
	t_list		*list;
	long int	num;

	i = 1;
	list = NULL;
	num = 0;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			list_error(&list, NULL);
		if (i == 1)
			list = ft_lstnew((int)num);
		else
			ft_lstadd_back(&list, ft_lstnew((int)num));
		i++;
	}
	return (list);
}

void	push_to_b_except_3(t_list **list1, t_list **list2)
{
	int		i;
	int		size_a;
	t_list	*new_head;

	if (*list1 == NULL)
		return ;
	i = 0;
	size_a = ft_lstsize(*list1);
	while (i < size_a - 3)
	{
		new_head = *list1;
		*list1 = new_head->next;
		new_head->next = *list2;
		*list2 = new_head;
		write (1, "pb\n", 3);
		i++;
	}
	positioning(list1);
	positioning(list2);
}

void	push_to_a(t_list **list1, t_list **list2)
{
	t_list	*ptr;

	if (*list1 == NULL)
		return ;
	ptr = (*list2)->next;
	(*list2)->next = *list1;
	*list1 = *list2;
	*list2 = ptr;
	write (1, "pa\n", 3);
}
