/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:40:04 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 17:14:48 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/*void print_stack(t_stack_node *stack) {
    printf("Stack contents:\n");
    while (stack) {
        printf("%d\n", stack->value); // Assuming the value of the node is an integer
        stack = stack->next;
    }
}*/
void	leaks()
{
	system("leaks push_swap");
}
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	bool			split;

	b = NULL;
	a = NULL;
	split = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		split = 1;
	}
	add_stack_a(&a, argv + 1);
	//print_stack(a);
	ft_check_sort(&a, &b);
	//print_stack(a);
	ft_free_stack(&a);
	ft_free_matrix(argv, split);
	atexit(leaks);
	return (0);
}
