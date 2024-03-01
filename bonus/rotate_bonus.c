/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:39:27 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 10:40:35 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_rotate_bonus(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_find_last_node_bonus(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra_bonus(t_stack_node **a, bool checker)
{
	ft_rotate_bonus(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb_bonus(t_stack_node **b, bool checker)
{
	ft_rotate_bonus(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr_bonus(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_rotate_bonus(a);
	ft_rotate_bonus(b);
	if (!checker)
		write(1, "rr\n", 3);
}
