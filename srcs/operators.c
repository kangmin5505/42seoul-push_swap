/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:33:27 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/29 16:34:26 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp_value;

	if (stack->num_values > 1)
	{
		temp_value = stack->head->value;
		stack->head->value = stack->head->next->value;
		stack->head->next->value = temp_value;
	}
}

void	push(t_stack *to_stack, t_stack *from_stack)
{
	t_node	*temp_node;

	if (from_stack->num_values > 0)
	{
		temp_node = from_stack->head;
		from_stack->head = from_stack->head->next;
		if (from_stack->num_values == 1)
			from_stack->tail = NULL;
		temp_node->next = to_stack->head;
		temp_node->prev = NULL;
		if (to_stack->num_values == 0)
		{
			to_stack->head = temp_node;
			to_stack->tail = temp_node;
		}
		else
		{
			to_stack->head->prev = temp_node;
			to_stack->head = temp_node;
		}
		to_stack->num_values += 1;
		from_stack->num_values -= 1;
	}
}

void	rotate(t_stack *stack)
{
	t_node	*temp_node;

	if (stack->num_values > 1)
	{
		temp_node = stack->head;
		stack->head = temp_node->next;
		temp_node->next->prev = NULL;
		temp_node->next = NULL;
		temp_node->prev = stack->tail;
		temp_node->prev->next = temp_node;
		stack->tail = temp_node;
	}
}

void	r_rotate(t_stack *stack)
{
	t_node	*temp_node;

	if (stack->num_values > 1)
	{
		temp_node = stack->tail;
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
		temp_node->next = stack->head;
		temp_node->prev = NULL;
		temp_node->next->prev = temp_node;
		stack->head = temp_node;
	}
}
