/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:56:08 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 16:30:49 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*closest(t_stack *b)
{
	t_stack	*node;
	t_stack	*close_node;

	node = b;
	close_node = node;
	while (node)
	{
		if (node -> num_moves < close_node -> num_moves)
			close_node = node;
		node = node ->next;
	}
	return (close_node);
}

static void	iteri_stack(t_stack *stack)
{
	t_stack	*node;
	int		position;

	node = stack;
	position = 0;
	if (stack)
	{
		while (node)
		{
			node -> position = position;
			position++;
			node = node -> next;
		}
	}
}

static void	correct_position(t_stack *s1, t_stack *s2)
{
	t_stack	*a;
	t_stack	*b;
	long	temp;

	a = s1;
	b = s2;
	while (b)
	{
		a = s1;
		temp = LONG_MAX;
		while (a)
		{
			if (b -> content < a -> content && a->content < temp)
			{
				temp = a -> content;
				b -> next_sorted = a;
			}
			a = a -> next;
		}
		if (temp == LONG_MAX)
			b -> next_sorted = min_node(s1);
		b = b -> next;
	}
}

static void	num_of_moves(t_stack *a, t_stack *b)
{
	int	num;

	if (b)
	{
		while (b)
		{
			num = b ->position;
			if (b -> position > stack_size(b) / 2)
				num = stack_size(b) - b -> position;
			if (b -> next_sorted -> position <= stack_size(a) / 2)
				num += b -> next_sorted -> position;
			else
				num += stack_size(a) - b -> next_sorted -> position;
			b -> num_moves = num;
			b = b -> next;
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = NULL;
	while (stack_size(*a) != 3)
		push_elem(b, a, 'b');
	mini_sort(a);
	while (*b)
	{
		iteri_stack(*a);
		iteri_stack(*b);
		correct_position(*a, *b);
		num_of_moves(*a, *b);
		node = closest(*b);
		if (node -> position <= stack_size(*b) / 2
			&& node-> next_sorted -> position <= stack_size(*a) / 2)
			rot_all(a, b, node);
		else if (node -> position > stack_size(*b) / 2
			&& node-> next_sorted -> position > stack_size(*a) / 2)
			r_rot_all(a, b, node);
		fix_stack(a, b, node);
		push_elem(a, b, 'a');
	}
	iteri_stack(*a);
	last_sort(a);
}
