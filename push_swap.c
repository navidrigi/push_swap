/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:49:06 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/18 16:28:35 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **list1, t_list **list2, int size_a)
{
	if (size_a == 2 && if_stack_is_sorted(*list1) == 0)
	{
		swap_a(*list1);
		write (1, "sa\n", 3);
	}
	else if (size_a == 3 && if_stack_is_sorted(*list1) == 0)
		sort_three(list1);
	else if (if_stack_is_sorted(*list1) == 0)
		sort_general(list1, list2);
}

void	free_list(t_list **list)
{
	t_list	*ptr;

	if (list == NULL || *list == NULL)
		return ;
	while (*list)
	{
		ptr = (*list)->next;
		free (*list);
		*list = ptr;
	}
	*list = NULL;
}

int	main(int argc, char **argv)
{
	int		size_a;
	t_list	*list1;
	t_list	*list2;

	if (argc < 2)
		return (1);
	if (correct_input_checker(argv) == 0)
		list_error(NULL, NULL);
	list1 = populating_list_1st_time(argc, argv);
	list2 = NULL;
	size_a = ft_lstsize(list1);
	indexing_process(list1, size_a + 1);
	push_swap(&list1, &list2, size_a);
	free_list(&list1);
	free_list(&list2);
	return (0);
}
