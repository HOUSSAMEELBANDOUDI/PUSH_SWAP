/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:18:58 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/09 13:50:49 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp_bonus(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	ft_mistake_bonus(t_stack_node **a, t_stack_node **b)
{
	ft_free_stack_bonus(a);
	ft_free_stack_bonus(b);
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_check_bonus(t_stack_node **a, t_stack_node **b, char *line)
{
	if (!ft_strcmp_bonus(line, "pa\n"))
		pa_bonus(a, b, true);
	else if (!ft_strcmp_bonus(line, "pb\n"))
		pb_bonus(b, a, true);
	else if (!ft_strcmp_bonus(line, "sa\n"))
		sa_bonus(a, true);
	else if (!ft_strcmp_bonus(line, "sb\n"))
		sb_bonus(b, true);
	else if (!ft_strcmp_bonus(line, "ss\n"))
		ss_bonus(a, b, true);
	else if (!ft_strcmp_bonus(line, "ra\n"))
		ra_bonus(a, true);
	else if (!ft_strcmp_bonus(line, "rb\n"))
		rb_bonus(b, true);
	else if (!ft_strcmp_bonus(line, "rr\n"))
		rr_bonus(a, b, true);
	else if (!ft_strcmp_bonus(line, "rra\n"))
		rra_bonus(a, true);
	else if (!ft_strcmp_bonus(line, "rrb\n"))
		rrb_bonus(b, true);
	else if (!ft_strcmp_bonus(line, "rrr\n"))
		rrr_bonus(a, b, true);
	else
		ft_mistake_bonus(a, b);
	free(line);
}

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
			ft_free_stack_bonus(&a);
			write(1, "Error\n", 6);
			return (0);
		}
		spl = ft_split_bonus(argv[i], ' ');
		add_stack_a_bonus(&a, spl);
		i++;
		ft_free_matrix_bonus(spl, 1);
	}
	ft_process_commands_bonus(&a, &b);
	ft_free_stack_bonus(&a);
	ft_free_stack_bonus(&b);
}
