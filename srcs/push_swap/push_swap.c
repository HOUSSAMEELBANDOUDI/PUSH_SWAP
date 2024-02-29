/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:40:04 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/29 11:33:29 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void    leaks()
{
    system("leaks push_swap");
}*/
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	bool			split;

	b = NULL;
	a = NULL;
	split = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		split = 1;
	}
	add_stack_a(&a, argv + 1);
	if (!ft_is_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, false);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(&a);
		else
			ft_sort_stack(&a, &b);
	}
	ft_free_stack(&a);
	ft_free_matrix(argv, split);
}
