/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:18:59 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/19 16:05:52 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target_b(t_stack_node *b, t_stack_node *a)
{
	t_stack_node	*current;
	long			flag;

	while (b)
	{
		current = a;
		flag = LONG_MAX;
		while (current)
		{
			if (b->value < current->value && current->value < flag)
			{
				b->target_node = current;
				flag = current->value;
			}
			current = current->next;
		}
		if (flag == LONG_MAX)
			b->target_node = ft_find_min(a);
		b = b->next;
	}
}

t_stack_node	*ft_find_min(t_stack_node *stack)
{
	t_stack_node	*min;

	if (!stack)
		return (NULL);
	min = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	ft_init_b(t_stack_node	*b, t_stack_node *a)
{
	ft_current_index(b);
	ft_current_index(a);
	ft_find_target_b(b, a);
}

void	ft_move_to_a(t_stack_node **b, t_stack_node **a)
{
	ft_push_to_top_a(a, (*b)->target_node);
	pa(a, b, false);
}
