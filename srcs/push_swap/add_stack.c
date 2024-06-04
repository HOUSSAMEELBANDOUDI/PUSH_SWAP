/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:49:18 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/15 17:08:00 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	add_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	long	value;

	i = 0;
	while (argv[i])
	{
		if (ft_error_syntax(argv[i]))
			ft_free_errors(a);
		value = ft_atoi(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			ft_free_errors(a);
		if (ft_repetion(*a, value))
			ft_free_errors(a);
		ft_add_end(a, value);
		i++;
	}
}
