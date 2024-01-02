/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:37:44 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:55:05 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int number)
{
	t_list	*ptr;

	ptr = (t_list *) malloc(sizeof(t_list));
	if (ptr == 0)
		exit (1);
	ptr->number = number;
	ptr->next = NULL;
	return (ptr);
}
