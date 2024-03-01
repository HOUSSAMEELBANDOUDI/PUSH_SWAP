/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:09:45 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 10:11:24 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static long	ft_atoi_bonus(const char *str)
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

void	add_stack_a_bonus(t_stack_node **a, char **argv)
{
	int	i;
	int	value;

	i = 0;
	while (argv[i])
	{
		if (ft_error_syntax_bonus(argv[i]))
			ft_free_errors_bonus(a);
		value = ft_atoi_bonus(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			ft_free_errors_bonus(a);
		if (ft_repetion_bonus(*a, value))
			ft_free_errors_bonus(a);
		ft_add_end_bonus(a, value);
		i++;
	}
}
