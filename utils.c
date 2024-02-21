/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:43 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 14:41:42 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_all(t_stack **a, t_stack **b, t_stack *node)
{
	while (node -> position && node -> next_sorted -> position)
	{
		rotate_list(b, 0);
		rotate_list(a, 0);
		ft_putendl_fd("rr", 1);
		node -> position--;
		node -> next_sorted -> position--;
	}
}

void	r_rot_all(t_stack **a, t_stack **b, t_stack *node)
{
	while (node -> position != stack_size(*b)
		&&node -> next_sorted -> position != stack_size(*a))
	{
		r_rotate_list(b, 0);
		r_rotate_list(a, 0);
		ft_putendl_fd("rrr", 1);
		node -> position++;
		node -> next_sorted -> position++;
	}
}

void	fix_stack(t_stack **a, t_stack **b, t_stack *node)
{
	if (node -> position != 0 && (node ->position <= stack_size(*b) / 2))
	{
		while (node -> position--)
			rotate_list(b, 'b');
	}
	else if (node -> position != 0 && (node ->position > stack_size(*b) / 2))
	{
		while (node -> position++ != stack_size(*b))
			r_rotate_list(b, 'b');
	}
	if (node -> next_sorted -> position != 0
		&& (node -> next_sorted -> position <= stack_size(*a) / 2))
	{
		while (node -> next_sorted -> position--)
			rotate_list(a, 'a');
	}
	else if (node -> next_sorted -> position != 0
		&& node -> next_sorted -> position > stack_size(*a) / 2)
	{
		while (node -> next_sorted -> position++ != stack_size(*a))
			r_rotate_list(a, 'a');
	}
}
