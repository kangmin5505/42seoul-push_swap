/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:42:42 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/31 00:20:11 by kangkim          ###   ########.fr       */
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
# define STACK_A 'a'
# define STACK_B 'b'

typedef struct s_node	t_node;

struct s_node
{
	int		data;
	int		rank;
	t_node	*next;
	t_node	*prev;
};

typedef struct s_stack	t_stack;
struct s_stack
{
	int		num_of_data;
	t_node	*head;
	t_node	*tail;
	char	stack_name;
};

/* main */
void	free_stack(t_stack **stack);
bool	check_sort(t_stack *stack_a);
bool	check_reverse_sort(t_stack *stack_b);

/* push_swap */
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	quick_sort_a(t_stack *stack_a, t_stack *stack_b, \
					int first, int last, int total_cnt);

/* push_swap_utils */
void	manual_algorithm(t_stack *stack);
void	manual_reverse_algorithm(t_stack *stack_a, t_stack *stack_b, \
								int total_cnt);

/* parse_argvs */
bool	parse_argvs(int argc, char *argv[], t_stack *stack_a);
bool	check_digit(char *str);
bool	check_range_nduplicated(char *str, t_stack *stack_a, int *nbr);
void	free_dpstr(char **strs);

/* stack */
void	init_stack(t_stack **stack, char stack_name);
void	init_node(t_node *node, t_node *next, t_node *prev, int nbr);
void	add_stack(t_stack *stack, int nbr);
void	set_rank(t_stack *stack, t_node *node);

/* operators */
void	swap(t_stack *stack);
void	push_to_from(t_stack *to_stack, t_stack *from_stack);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);

#endif
