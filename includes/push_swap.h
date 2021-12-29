/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:42:42 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/29 12:33:54 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"

# include <stdio.h>

typedef struct s_node	t_node;

struct s_node
{
	int		value;
	t_node	*next;
	t_node	*prev;
};

typedef struct s_stack	t_stack;
struct s_stack
{
	t_node	*head;
	t_node	*tail;
};

/* push_swap */
void	free_stack(t_stack **stack);

/* parse_argvs */
bool	parse_argvs(int argc, char *argv[], t_stack *stack_a);
bool	check_digit(char *str);
bool	check_range_nduplicated(char *str, t_stack *stack_a, int *nbr);

/* stack */
void	init_stack(t_stack **stack);
void	init_node(t_node *node, t_node *next, t_node *prev, int nbr);
void	push_stack(t_stack *stack, int nbr);

#endif
