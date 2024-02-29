/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:28:04 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/18 15:38:40 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	median = ft_stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	ft_find_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	long			flag;

	while (a)
	{
		current = b;
		flag = LONG_MIN;
		while (current)
		{
			if (a->value > current->value && current->value > flag)
			{
				a->target_node = current;
				flag = current->value;
			}
			current = current->next;
		}
		if (flag == LONG_MIN)
			a->target_node = ft_find_max(b);
		a = a->next;
	}
}

void	ft_push_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_median)
			a->push_cost = len_a - a->index;
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - a->target_node->index;
		a = a->next;
	}
}

void	ft_find_cheapest(t_stack_node *stack)
{
	long			value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < value)
		{
			value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	ft_init_a(t_stack_node	*a, t_stack_node *b)
{
	ft_current_index(a);
	ft_current_index(b);
	ft_find_target_a(a, b);
	ft_push_cost_a(a, b);
	ft_find_cheapest(a);
}
