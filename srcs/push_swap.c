/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:13:46 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/31 00:25:19 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_b(t_stack *stack_a, t_stack *stack_b, \
					int	first, int last, int total_cnt)
{
	int		median_rank;
	int		pa_cnt;
	t_node	*curr;

	if (total_cnt <= 2 || check_reverse_sort(stack_b) == true)
	{
		manual_reverse_algorithm(stack_a, stack_b, total_cnt);
		return ;
	}
	median_rank = (first + last) / 2;
	pa_cnt = 0;
	curr = stack_b->head;
	while (check_reverse_sort(stack_b) != true && pa_cnt != (total_cnt / 2))
	{
		if (curr->rank < median_rank)
		{
			push_to_from(stack_a, stack_b);
			pa_cnt += 1;
		}
		else
			rotate(stack_b);
		curr = stack_b->head;
	}
	quick_sort_b(stack_a, stack_b, first - pa_cnt, last, total_cnt - pa_cnt);
	while (pa_cnt-- && stack_b->num_of_data != 0)
		push_to_from(stack_b, stack_a);
}

void	quick_sort_a(t_stack *stack_a, t_stack *stack_b, \
					 int first, int last, int total_cnt)
{
	int		median_rank;
	int		pb_cnt;
	t_node	*curr;

	if (total_cnt <= 3 || check_sort(stack_a) == true)
	{
		manual_algorithm(stack_a);
		return ;
	}
	median_rank = (first + last) / 2;
	pb_cnt = 0;
	curr = stack_a->head;
	while (check_sort(stack_a) != true && pb_cnt != (total_cnt / 2))
	{
		if (curr->rank > median_rank)
		{
			push_to_from(stack_b, stack_a);
			pb_cnt += 1;
		}
		else
			rotate(stack_a);
		curr = stack_a->head;
	}
	quick_sort_a(stack_a, stack_b, first, last - pb_cnt, total_cnt - pb_cnt);
	quick_sort_b(stack_a, stack_b, median_rank + 1, last, pb_cnt);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	first;
	int last;
	if (stack_a->num_of_data <= 3)
		manual_algorithm(stack_a);
	else
	{
		first = 1;
		last = stack_a->num_of_data;
		quick_sort_a(stack_a, stack_b, first, last, stack_a->num_of_data);
	}
}
