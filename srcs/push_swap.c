/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:32:31 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/29 17:12:23 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_node	*node;
	t_node	*curr;

	curr = (*stack)->head;
	while (curr)
	{
		node = curr;
		curr = curr->next;
		free(node);
	}
	free(*stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*node;

	if (argc > 1)
	{
		init_stack(&stack_a);
		init_stack(&stack_b);
		if (parse_argvs(argc, argv, stack_a) == false)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		printf("========================= check stack_a value ============================\n");
		node = stack_a->head;
		while (node)
		{
			printf("value : %d\n", node->value);
			printf("now : %p\n", node);
			printf("prev : %p\n", node->prev);
			printf("next : %p\n", node->next);
			node = node->next;
		}
		printf("num_values : %d\n", stack_a->num_values);
		printf("========================= end  ============================\n");
		printf("========================= check stack_b value ============================\n");
		node = stack_b->head;
		while (node)
		{
			printf("value : %d\n", node->value);
			printf("now : %p\n", node);
			printf("prev : %p\n", node->prev);
			printf("next : %p\n", node->next);
			node = node->next;
		}
		printf("num_values : %d\n", stack_b->num_values);
		printf("========================= end  ============================\n");
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
