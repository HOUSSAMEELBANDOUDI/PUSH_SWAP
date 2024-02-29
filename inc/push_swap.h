/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:27:48 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/29 15:41:42 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int		ft_error_syntax(char *str);
int		ft_repetion(t_stack_node *a, int value);
void	ft_free_stack(t_stack_node **stack);
void	ft_free_errors(t_stack_node **a);
void	ft_free_matrix(char **argv, bool split);
void	add_stack_a(t_stack_node **a, char **argv);
char	**ft_split(char *s, char c);

void            ft_add_end(t_stack_node **stack, int value);
t_stack_node    *ft_find_last_node(t_stack_node *head);
int             ft_stack_len(t_stack_node *stack);
void            ft_delete_first(t_stack_node **head);
void            ft_add_begginer(t_stack_node **stack_a, t_stack_node **stack_b);

void    sa(t_stack_node **a, bool print);
void    sb(t_stack_node **b, bool print);
void    ss(t_stack_node **a, t_stack_node **b, bool print);
void    ra(t_stack_node **a, bool print);
void    rb(t_stack_node **b, bool print);
void    rr(t_stack_node **a, t_stack_node **b, bool print);
void    rra(t_stack_node **a, bool print);
void    rrb(t_stack_node **b, bool print);
void    rrr(t_stack_node **a, t_stack_node **b, bool print);
void    pa(t_stack_node **a, t_stack_node **b, bool print);
void    pb(t_stack_node **b, t_stack_node **a, bool print);
void    ft_double_rotate(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void    ft_double_rev_rotate(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void    ft_push_to_top_b(t_stack_node **b, t_stack_node *cheapest);
void    ft_push_to_top_a(t_stack_node **a, t_stack_node *cheapest);

t_stack_node    *ft_find_max(t_stack_node *stack); 
void            ft_sort_three(t_stack_node **a); 
bool            ft_is_sorted(t_stack_node *stack);
void            ft_current_index(t_stack_node *stack);
void            ft_find_target_a(t_stack_node *a, t_stack_node *b);
void            ft_push_cost_a(t_stack_node *a, t_stack_node *b);
void            ft_find_cheapest(t_stack_node *stack);
void            ft_init_a(t_stack_node *a, t_stack_node *b);
t_stack_node    *ft_return_cheapest(t_stack_node *stack);
void            ft_move_to_b(t_stack_node **a, t_stack_node **b);
void            ft_find_target_b(t_stack_node *b, t_stack_node *a);
t_stack_node    *ft_find_min(t_stack_node *stack);
void            ft_init_b(t_stack_node *b, t_stack_node *a);
void            ft_move_to_a(t_stack_node **b, t_stack_node **a);
void            ft_min_top(t_stack_node **a);
void            ft_sort_stack(t_stack_node **a, t_stack_node **b);
# endif