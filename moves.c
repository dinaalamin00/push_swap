/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:22:27 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 16:36:55 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*pop(t_stack **top)
{
	t_stack	*temp;

	temp = *top;
	*top = (*top)-> next;
	temp -> next = NULL;
	return (temp);
}

void	swap_elem(t_stack **top, char stack)
{
	t_stack		*temp;

	if ((*top) && (*top)-> next)
	{
		temp = (*top)-> next;
		(*top)-> next = temp-> next;
		temp -> next = (*top);
		(*top) = temp;
		if (stack == 'a')
			ft_putendl_fd("sa", 1);
		else if (stack == 'b')
			ft_putendl_fd("sb", 1);
		else
			return ;
	}
}

void	push_elem(t_stack **s1, t_stack **s2, char stack)
{
	t_stack	*node;

	if (!(*s2))
		return ;
	node = pop(s2);
	push_front(s1, node);
	if (stack == 'a')
		ft_putendl_fd("pa", 1);
	else if (stack == 'b')
		ft_putendl_fd("pb", 1);
	else
		return ;
}

void	rotate_list(t_stack **top, char stack)
{
	t_stack	*node;

	if (*top && (*top)-> next)
	{
		node = pop(top);
		push_back(top, node);
		if (stack == 'a')
			ft_putendl_fd("ra", 1);
		else if (stack == 'b')
			ft_putendl_fd("rb", 1);
		else
			return ;
	}
}

void	r_rotate_list(t_stack **top, char stack)
{
	t_stack	*node;
	t_stack	*temp;

	if (*top && (*top)-> next)
	{
		node = *top;
		while (node -> next -> next)
		{
			node = node -> next;
		}
		temp = node -> next;
		node -> next = NULL;
		push_front(top, temp);
		if (stack == 'a')
			ft_putendl_fd("rra", 1);
		else if (stack == 'b')
			ft_putendl_fd("rrb", 1);
		else
			return ;
	}
}
