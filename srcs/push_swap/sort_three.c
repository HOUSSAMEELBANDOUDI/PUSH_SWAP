/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:23:19 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/29 19:49:02 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_find_max(t_stack_node *stack)
{
	t_stack_node	*max;

	if (!stack)
		return (NULL);
	max = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	ft_sort_three(t_stack_node **a)
{
	t_stack_node	*big;

	big = ft_find_max(*a);
	if (*a == big)
		ra(a, false);
	else if ((*a)->next == big)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

bool	ft_is_sorted(t_stack_node *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_check_sort(t_stack_node **a, t_stack_node **b)
{
	if (!ft_is_sorted(*a))
	{
		if (ft_stack_len(*a) == 2)
			sa(a, false);
		else if (ft_stack_len(*a) == 3)
			ft_sort_three(a);
		else
			ft_sort_stack(a, b);
	}
}
