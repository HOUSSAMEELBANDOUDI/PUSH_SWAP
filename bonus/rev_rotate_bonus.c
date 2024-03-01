/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:37:44 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 10:39:19 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_rev_rotate_bonus(t_stack_node **stack)
{
	t_stack_node	*lst;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	lst = ft_find_last_node_bonus(*stack);
	lst->prev->next = NULL;
	lst->next = *stack;
	lst->prev = NULL;
	(*stack)->prev = lst;
	*stack = lst;
}

void	rra_bonus(t_stack_node **a, bool checker)
{
	ft_rev_rotate_bonus(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb_bonus(t_stack_node **b, bool checker)
{
	ft_rev_rotate_bonus(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr_bonus(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_rev_rotate_bonus(a);
	ft_rev_rotate_bonus(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
