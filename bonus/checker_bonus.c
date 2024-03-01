/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:18:58 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 17:07:37 by hel-band         ###   ########.fr       */
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
}
void    leaks()
{
    system("leaks checker");
}
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*next_line;
	int				len;
	bool			split;

	b = NULL;
	a = NULL;
	split = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split_bonus(argv[1], ' ');
		split = 1;
	}
	add_stack_a_bonus(&a, argv + 1);
	len = ft_stack_len_bonus(a);
	next_line = get_next_line(0);
	while (next_line)
	{
		ft_check_bonus(&a, &b, next_line);
		next_line = get_next_line(0);
	}
	if (ft_is_sorted_bonus(a) && ft_stack_len_bonus(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack_bonus(&a);
	ft_free_stack_bonus(&b);
	ft_free_matrix_bonus(argv, split);
	free(next_line);
	atexit(leaks);
} 
