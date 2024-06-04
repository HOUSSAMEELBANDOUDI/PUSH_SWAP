/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:32:16 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 17:05:15 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include "push_swap.h"

int				ft_error_syntax_bonus(char *str);
int				ft_repetion_bonus(t_stack_node *a, int value);
void			ft_free_stack_bonus(t_stack_node **stack);
void			ft_free_errors_bonus(t_stack_node **a);
void			ft_free_matrix_bonus(char **argv, bool split);
void			add_stack_a_bonus(t_stack_node **a, char **argv);
char			**ft_split_bonus(char *s, char c);

void			ft_add_end_bonus(t_stack_node **stack, int value);
t_stack_node	*ft_find_last_node_bonus(t_stack_node *head);
int				ft_stack_len_bonus(t_stack_node *stack);
void			ft_delete_first_bonus(t_stack_node **head);
void			ft_add_begginer_bonus(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			sa_bonus(t_stack_node **a, bool print);
void			sb_bonus(t_stack_node **b, bool print);
void			ss_bonus(t_stack_node **a, t_stack_node **b, bool print);
void			ra_bonus(t_stack_node **a, bool print);
void			rb_bonus(t_stack_node **b, bool print);
void			rr_bonus(t_stack_node **a, t_stack_node **b, bool print);
void			rra_bonus(t_stack_node **a, bool print);
void			rrb_bonus(t_stack_node **b, bool print);
void			rrr_bonus(t_stack_node **a, t_stack_node **b, bool print);
void			pa_bonus(t_stack_node **a, t_stack_node **b, bool print);
void			pb_bonus(t_stack_node **b, t_stack_node **a, bool print);
void			ft_process_commands_bonus(t_stack_node **a, t_stack_node **b);

bool			ft_is_sorted_bonus(t_stack_node *stack);
int				ft_strcmp_bonus(char *str1, char *str2);
void			ft_mistake_bonus(t_stack_node **a, t_stack_node **b);
void			ft_check_bonus(t_stack_node **a, t_stack_node **b, char *line);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char			*get_next_line(int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_calloc(size_t count, size_t size);
int				ft_index(char *s);
int				ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_strdup(char const *s1);
char			*ft_add(char **str, int i);
char			*ft_result(char **str, char **dst, int i);
char			*ft_get_line(char **str, char **dst, char **buffer, int fd);

#endif
