/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:43:54 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/29 19:21:05 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_syntax(char *str_nbr)
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

void	ft_free_stack(t_stack_node **stack)
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

int	ft_repetion(t_stack_node *head, int value)
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

void	ft_free_matrix(char **argv, bool split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	ft_free_errors(t_stack_node **stack)
{
	ft_free_stack(stack);
	write(1, "Error\n", 6);
	exit(1);
}
