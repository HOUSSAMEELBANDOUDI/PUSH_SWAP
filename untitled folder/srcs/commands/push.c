/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:25:16 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/19 13:41:12 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_add_begginer(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	ft_add_begginer(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}

void	ft_push_to_top_a(t_stack_node **a, t_stack_node *cheapest)
{
	while (*a != cheapest)
	{
		if (cheapest->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	ft_push_to_top_b(t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest)
	{
		if (cheapest->above_median)
			rb(b, false);
		else
			rrb(b, false);
	}
}
