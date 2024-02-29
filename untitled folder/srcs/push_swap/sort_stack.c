/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:50:22 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/19 16:12:52 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = ft_stack_len(*a);
	if (len_a-- > 3 && !ft_is_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !ft_is_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !ft_is_sorted(*a))
	{
		ft_init_a(*a, *b);
		ft_move_to_b(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_b(*b, *a);
		ft_move_to_a(b, a);
	}
	ft_current_index(*a);
	ft_min_top(a);
}

t_stack_node	*ft_return_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_move_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = ft_return_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		ft_double_rotate(a, b, cheapest);
	if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		ft_double_rev_rotate(a, b, cheapest);
	ft_push_to_top_a(a, cheapest);
	ft_push_to_top_b(b, cheapest);
	pb(b, a, false);
}

void	ft_min_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = ft_find_min(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
