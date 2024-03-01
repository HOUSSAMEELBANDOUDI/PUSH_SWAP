/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:13:00 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 10:14:41 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_error_syntax_bonus(char *str_nbr)
{
	if (!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

void	ft_free_stack_bonus(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	ft_repetion_bonus(t_stack_node *head, int value)
{
	if (!head)
		return (0);
	while (head)
	{
		if (head->value == value)
			return (1);
		head = head->next;
	}
	return (0);
}

void	ft_free_matrix_bonus(char **argv, bool split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	ft_free_errors_bonus(t_stack_node **stack)
{
	ft_free_stack_bonus(stack);
	write(1, "Error\n", 6);
	exit(1);
}
