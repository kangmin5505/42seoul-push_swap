/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:46:24 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/29 12:26:12 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_range_nduplicated(char *str, t_stack *stack_a, int *nbr)
{
	long	num;
	t_node	*curr;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	curr = stack_a->head;
	while (curr)
	{
		if (curr->value == (int)num)
			return (false);
		curr = curr->next;
	}
	*nbr = (int)num;
	return (true);
}

bool	check_digit(char *str)
{
	while (*str == '+' || *str == '-' || *str == ' ')
		str++;
	while (*str)
	{
		if (ft_isdigit((int)*str) == 0)
			return (false);
		str++;
	}
	return (true);
}

bool	parse_argvs(int argc, char *argv[], t_stack *stack_a)
{
	char	**strs;
	int		argv_idx;
	int		str_idx;
	int		nbr;

	argv_idx = 1;
	while (argv_idx < argc)
	{
		strs = ft_split(argv[argv_idx], ' ');
		str_idx = 0;
		while (strs[str_idx])
		{
			if (check_digit(strs[str_idx]) == false || \
				check_range_nduplicated(strs[str_idx], stack_a, &nbr) == false)
			{
				free(strs);
				return (false);
			}
			push_stack(stack_a, nbr);
			str_idx++;
		}
		free(strs);
		argv_idx++;
	}
	return (true);
}
