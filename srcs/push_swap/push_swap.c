/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:40:04 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/09 13:48:08 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**spl;
	int				i;

	b = NULL;
	a = NULL;
	i = 1;
	while (argv[i] && argc > 1)
	{
		if (!argv[i][0] || argv[i][0] == 32)
		{
			write(1, "Error\n", 6);
			ft_free_stack(&a);
			return (0);
		}
		spl = ft_split(argv[i], ' ');
		add_stack_a(&a, spl);
		i++;
		ft_free_matrix(spl, 1);
	}
	ft_check_sort(&a, &b);
	ft_free_stack(&a);
	return (0);
}
