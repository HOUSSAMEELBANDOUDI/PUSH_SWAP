/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:33:09 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 17:10:54 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	ft_is_sorted_bonus(t_stack_node *stack)
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

void	ft_initialize_stack_bonus(int argc, char **argv,
			t_stack_node **a, bool *split)
{
	*a = NULL;
	*split = false;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
	else if (argc == 2)
	{
		argv = ft_split_bonus(argv[1], ' ');
		*split = true;
	}
	add_stack_a_bonus(a, argv + 1);
}

void	ft_process_commands_bonus(t_stack_node **a, t_stack_node **b)
{
	char	*next_line;
	int		len;

	len = ft_stack_len_bonus(*a);
	next_line = get_next_line(0);
	while (next_line)
	{
		ft_check_bonus(a, b, next_line);
		next_line = get_next_line(0);
	}
	if (ft_is_sorted_bonus(*a) && ft_stack_len_bonus(*a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
