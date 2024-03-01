/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:21:29 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 10:23:48 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack_node	*ft_find_last_node_bonus(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_add_end_bonus(t_stack_node **stack, int value)
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
		last = ft_find_last_node_bonus(*stack);
		last->next = current;
		current->prev = last;
	}
}

int	ft_stack_len_bonus(t_stack_node *stack)
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

void	ft_delete_first_bonus(t_stack_node **head)
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

void	ft_add_begginer_bonus(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}
