/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_values_checking.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:51:13 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/15 11:51:13 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	correct_input_checker(char **argv)
{
	int	i;
	int	number_of_zeros;

	i = 1;
	number_of_zeros = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0)
			return (0);
		number_of_zeros += if_argv_is_zero(argv[i]);
		i++;
	}
	if (number_of_zeros > 1)
		return (0);
	if (duplicate_checker(argv))
		return (0);
	return (1);
}

int	if_argv_is_zero(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i])
		return (0);
	return (1);
}

int	duplicate_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (i != j && ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	list_error(t_list **list1, t_list **list2)
{
	if (list1 == NULL || *list1 != NULL)
		free_list(list1);
	if (list2 == NULL || *list2 != NULL)
		free_list(list2);
	write (1, "Error\n", 6);
	exit(1);
}
