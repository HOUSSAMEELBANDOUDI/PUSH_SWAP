/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:27:48 by hel-band          #+#    #+#             */
/*   Updated: 2024/02/13 11:37:52 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> // To use bool flags, e.g., to print or not to print
# include <limits.h>  // To define MIN and MAX macros
# include <stdlib.h>
# include <unistd.h>

typedef struct  s_stack_node // A container of data
{
	int                 value;                // The number to sort
	int                 index;                // The number's position in the stack
	int                 push_cost;            // How many commands in total
	bool                above_median;         // Used to calculate `push_cost`
	bool                cheapest;             // The node that is the cheapest to do commands
	struct s_stack_node *target_node;     // The target node of a node in the opposite stack
	struct s_stack_node *next;            // A pointer to the next node
	struct s_stack_node *prev;            // A pointer to the previous node
}	t_stack_node;                          // The "shortened name", "t_stack_node".

// ***Handle errors
int		ft_error_syntax(char *str);
int		ft_repetion(t_stack_node *a, int value);
void	ft_free_stack(t_stack_node **stack);
void	ft_free_errors(t_stack_node **a);

// ***Stack initiation
void	add_stack_a(t_stack_node **a, char **argv); // Initiate stack `a` before processing
char	**ft_split(char *s, char c);               // To handle input of numbers as a string argument, e.g., enclosed in ' '

// *** linked list utils ***
void            ft_add_end(t_stack_node **stack, int value);
t_stack_node	*ft_find_last_node(t_stack_node *head);
int		        ft_stack_len(t_stack_node *stack);
void	        ft_delete_first(t_stack_node **head);
void	        ft_add_begginer(t_stack_node **stack_a, t_stack_node **stack_b);

// ***Commands
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);
void	ft_double_rotate(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void	ft_double_rev_rotate(t_stack_node **a, t_stack_node **, t_stack_node *cheapest);
void	ft_push_to_top_b(t_stack_node **b, t_stack_node *cheapest);
void	ft_push_to_top_a(t_stack_node **a, t_stack_node *cheapest);

// ****sorts
t_stack_node	*ft_find_max(t_stack_node *stack); 
void			ft_sort_three(t_stack_node **a); 
bool			ft_is_sorted(t_stack_node *stack);
void    		ft_current_index(t_stack_node *stack);
void    		ft_find_target_a(t_stack_node *a, t_stack_node *b);
void    		ft_push_cost_a(t_stack_node *a, t_stack_node *b);
void    		ft_find_cheapest(t_stack_node *stack);
void			ft_init_a(t_stack_node	*a, t_stack_node *b);
t_stack_node	*ft_return_cheapest(t_stack_node *stack);
void    		ft_move_to_b(t_stack_node **a, t_stack_node **b);
void			ft_find_target_b(t_stack_node *b, t_stack_node *a);
t_stack_node    *ft_find_min(t_stack_node *stack);
void	ft_init_b(t_stack_node	*b, t_stack_node *a);
void	ft_move_to_a(t_stack_node **b, t_stack_node **a);
void    ft_min_top(t_stack_node **a);
void	ft_sort_stack(t_stack_node **a, t_stack_node **b);

#endif // PUSH_SWAP_H
