/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:18:58 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/26 18:19:33 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strcmp(char *str1, char *str2)
{
    while (*str1 == *str2 && *str1)
    {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

void    ft_mistake(t_stack_node **a, t_stack_node **b)
{
    ft_free_stack(a);
    ft_free_stack(b);
    write(1, "Error\n", 6);
    exit(1);
}

void ft_check(t_stack_node **a, t_stack_node **b, char *line)
{
    if (!ft_strcmp(line, "pa\n"))
        pa(a, b, true);
    else if (!ft_strcmp(line, "pb\n"))
        pb(b, a, true);
    else if (!ft_strcmp(line, "sa\n"))
        sa(a, true);
    else if (!ft_strcmp(line, "sb\n"))
        sb(b, true);
    else if (!ft_strcmp(line, "ss\n"))
        ss(a, b, true);
    else if (!ft_strcmp(line, "ra\n"))
        ra(a, true);
    else if (!ft_strcmp(line, "rb\n"))
        rb(b, true);
    else if (!ft_strcmp(line, "rr\n"))
        rr(a, b, true);
    else if (!ft_strcmp(line, "rra\n"))
        rra(a, true);
    else if (!ft_strcmp(line, "rrb\n"))
        rrb(b, true);
    else if (!ft_strcmp(line, "rrr\n"))
        rrr(a, b, true);
    else
        ft_mistake(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
    char            *next_line;
    int             len;

	b = NULL;
	a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	add_stack_a(&a, argv + 1);
	len = ft_stack_len(a);
    next_line = get_next_line(0);
    while (next_line)
    {
        ft_check(&a, &b, next_line);
        next_line = get_next_line(0);
    }
    if (ft_is_sorted(a) && ft_stack_len(a) == len)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
	ft_free_stack(&a);
}