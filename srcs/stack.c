/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:09:15 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/29 14:42:46 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack)
{
	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	(*stack)->head = NULL;
	(*stack)->tail = NULL;
	(*stack)->num_values = 0;
}

void	init_node(t_node *node, t_node *next, t_node *prev, int nbr)
{
	node->value = nbr;
	node->next = next;
	node->prev = prev;
}

void	push_stack(t_stack *stack, int nbr)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (stack->head == NULL)
	{
		init_node(node, NULL, NULL, nbr);
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		init_node(node, NULL, stack->tail, nbr);
		stack->tail->next = node;
		stack->tail = node;
	}
	stack->num_values += 1;
}
