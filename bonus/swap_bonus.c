/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:40:46 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 10:41:47 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_swap_bonus(t_stack_node **head)
{
	int	tmp;

	if (!*head || !head || !(*head)->next)
		return ;
	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
}

void	sa_bonus(t_stack_node	**a, bool checker)
{
	ft_swap_bonus(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb_bonus(t_stack_node **b, bool checker)
{
	ft_swap_bonus(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss_bonus(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_swap_bonus(a);
	ft_swap_bonus(b);
	if (!checker)
		write(1, "ss\n", 3);
}
