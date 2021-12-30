/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:00:45 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/31 00:20:02 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manual_algorithm(t_stack *stack)
{
	if (stack->num_of_data == 2)
		swap(stack);
	while (check_sort(stack) == false)
	{
		if (stack->head->data < stack->tail->data)
			swap(stack);
		else if (stack->head->data > stack->head->next->data)
			rotate(stack);
		else
			r_rotate(stack);
	}
}

void	manual_reverse_algorithm(t_stack *stack_a, t_stack *stack_b, \
								 int total_cnt)
{
	if (check_reverse_sort(stack_b) == true)
		while (total_cnt--)
			push_to_from(stack_a, stack_b);
	else
	{
		swap(stack_b);
		while (total_cnt--)
			push_to_from(stack_a, stack_b);
	}
}
