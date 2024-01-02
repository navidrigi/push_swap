/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:31:56 by narigi-e          #+#    #+#             */
/*   Updated: 2023/09/18 13:38:38 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_list
{
	int				number;
	int				index;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}				t_list;

void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstnew(int content);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);

void			reverse_rotate_a(t_list **list);
void			reverse_rotate_b(t_list **list);
void			rotate_a(t_list **list);
void			rotate_b(t_list **list);
void			sort_three(t_list **list);
int				highest_index(t_list *list);
void			swap_a(t_list *list);
// void	push_to_b(t_list **list1, t_list **list2);
void			push_to_a(t_list **list1, t_list **list2);
// int				find_smallest(t_list *list);
// int				find_position(t_list *list, int num);
// void	keep_rotating(t_list **list, int pos);
// void	keep_reverse_rotating(t_list **list, int size, int pos);
// int 	repeat_checker(t_list *list, int size);
// void			sort_array(int *array, int size);
int				if_stack_is_sorted(t_list *list);
int				ft_isdigit(char *str);
long int		ft_atoi(char *nptr);
void			indexing_process(t_list *list, int size);
// void			indexing(t_list *list, int *array, int size);
void			positioning(t_list **list);
void			push_to_b_except_3(t_list **list1, t_list **list2);
int				target_position(t_list **list, int index, int target_indx,
					int target_pos);
void			target_positioning(t_list **list1, t_list **list2);
int				lowest_index_position(t_list *list);
// int	    finding_position_with_index(t_list *list, int index);
// void    list_a_cost(t_list **list1, t_list **list2);
// void	list_b_cost(t_list **list);
void			get_cost(t_list **stack_a, t_list **stack_b);
void			free_list(t_list **list);
void			list_error(t_list **list1, t_list **list2);
void			final_moves(t_list **list1, t_list **list2, int cost_a,
					int cost_b);
void			rotate_both(t_list **list1, t_list **list2, int *cost_a,
					int *cost_b);
void			rrotate_both(t_list **list1, t_list **list2, int *cost_a,
					int *cost_b);
void			rotate_a_with_costing(t_list **list1, int *cost_a);
void			rotate_b_with_costing(t_list **list2, int *cost_b);

void			moving_lowest_position_to_top(t_list **list1);
void			push_swap(t_list **list1, t_list **list2, int size_a);
void			sort_general(t_list **list1, t_list **list2);
int				correct_input_checker(char **argv);
int				if_argv_is_zero(char *argv);
t_list			*populating_list_1st_time(int argc, char **argv);
void			moving_least_cost(t_list **list1, t_list **list2);
int				abss(int n);
int				ft_strcmp(char *s1, char *s2);
int				duplicate_checker(char **argv);

#endif
