/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:41:00 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/18 22:18:56 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack_node **stack)
{
	t_stack_node	*lst;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	lst = ft_find_last_node(*stack);
	lst->prev->next = NULL;
	lst->next = *stack;
	lst->prev = NULL;
	(*stack)->prev = lst;
	*stack = lst;
}

void	rra(t_stack_node **a, bool checker)
{
	ft_rev_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool checker)
{
	ft_rev_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}

void	ft_double_rev_rotate(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
	{
		rrr(a, b, false);
	}
	ft_current_index(*a);
	ft_current_index(*b);
}
