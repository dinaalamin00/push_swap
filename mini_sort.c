/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:56:05 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 14:33:52 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_node(t_stack *a)
{
	t_stack	*node;
	int		min;
	t_stack	*min_node;

	node = a;
	min_node = NULL;
	if (a)
	{
		min = node ->content;
		min_node = node;
		while (node)
		{
			if (node-> content < min)
			{
				min = node-> content;
				min_node = node;
			}
			node = node -> next;
		}
	}
	return (min_node);
}

int	is_max(t_stack *a)
{
	t_stack	*node;
	int		max;
	int		cnt;
	int		position;

	node = a;
	position = 0;
	cnt = 0;
	if (a)
	{
		max = node ->content;
		while (node)
		{
			if (node-> content > max)
			{
				max = node-> content;
				position = cnt;
			}
			node = node -> next;
			cnt++;
		}
	}
	return (position + 1);
}

int	is_min(t_stack *a)
{
	t_stack	*node;
	int		min;
	int		cnt;
	int		position;

	node = a;
	position = 0;
	cnt = 0;
	if (a)
	{
		min = node ->content;
		while (node)
		{
			if (node-> content < min)
			{
				min = node-> content;
				position = cnt;
			}
			node = node -> next;
			cnt++;
		}
	}
	return (position);
}

void	mini_sort(t_stack **a)
{
	int	position;

	position = is_max(*a);
	if (position == 2)
		r_rotate_list(a, 'a');
	else if (position == 1)
		rotate_list(a, 'a');
	if (is_sorted(*a))
		return ;
	else
		swap_elem(a, 'a');
}

void	last_sort(t_stack **a)
{
	int	min_pos;

	min_pos = is_min(*a);
	if (min_pos <= stack_size(*a) / 2)
	{
		while (min_pos--)
			rotate_list(a, 'a');
	}
	else
	{
		while (min_pos++ != stack_size(*a))
			r_rotate_list(a, 'a');
	}
}
