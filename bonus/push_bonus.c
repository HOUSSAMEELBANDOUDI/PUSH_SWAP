/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:36:37 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 10:37:27 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa_bonus(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_add_begginer_bonus(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb_bonus(t_stack_node **b, t_stack_node **a, bool checker)
{
	ft_add_begginer_bonus(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
