/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:17:15 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 16:39:45 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				position;
	struct s_stack	*next_sorted;
	int				num_moves;
}	t_stack;

void	assign_args(t_stack **stack, int argc, char **argv);
int		is_sorted(t_stack *stack);
char	*join(char const *s1, char const *s2);
t_stack	*create_elem(t_stack **stack, int content);
void	push_back(t_stack **begin_list, t_stack	*new);
void	push_front(t_stack **begin_list, t_stack *new);
int		stack_size(t_stack *lst);
void	swap_elem(t_stack **top, char stack);
void	push_elem(t_stack **s1, t_stack **s2, char stack);
void	rotate_list(t_stack **top, char stack);
void	r_rotate_list(t_stack **top, char stack);
void	rot_all(t_stack **a, t_stack **b, t_stack *node);
void	r_rot_all(t_stack **a, t_stack **b, t_stack *node);
void	fix_stack(t_stack **a, t_stack **b, t_stack *node);
int		str_to_int(char **nptr, int index, t_stack **a);
char	**ft_free(char **ptr);
void	free_stack(t_stack **stack);
void	handle_error(t_stack **a, t_stack **b);
void	mini_sort(t_stack **a);
void	sort(t_stack **a, t_stack **b);
t_stack	*min_node(t_stack *a);
void	last_sort(t_stack **a);
int		is_max(t_stack *a);
int		is_min(t_stack *a);
char	*get_next_line(int fd);
void	exec_move(t_stack **a, t_stack **b, char *move);
#endif