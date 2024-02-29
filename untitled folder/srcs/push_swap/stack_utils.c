/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:10:24 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/15 17:19:35 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_find_last_node(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_add_end(t_stack_node **stack, int value)
{
	t_stack_node	*current;
	t_stack_node	*last;

	if (!stack)
		return ;
	current = malloc(sizeof(t_stack_node));
	if (!current)
		return ;
	current->next = NULL;
	current->value = value;
	if (!*stack)
	{
		current->prev = NULL;
		*stack = current;
	}
	else
	{
		last = ft_find_last_node(*stack);
		last->next = current;
		current->prev = last;
	}
}

int	ft_stack_len(t_stack_node *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	ft_delete_first(t_stack_node **head)
{
	t_stack_node	*current;

	if (!head || !*head)
		return ;
	current = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(current);
}

void	ft_add_begginer(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*current;

	if (!stack_b || !*stack_b)
		return ;
	current = *stack_b;
	ft_delete_first(stack_b);
	current->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = current;
	*stack_a = current;
}
