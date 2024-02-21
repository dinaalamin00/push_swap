/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:38:55 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 16:39:10 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_elem(t_stack **stack, int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	node -> content = content;
	node -> next = NULL;
	return (node);
}

void	push_back(t_stack **begin_list, t_stack	*new)
{
	t_stack	*node;

	if (new)
	{
		node = *begin_list;
		if (node != NULL)
		{
			while (node -> next != NULL)
			{
				node = node -> next;
			}
			node -> next = new;
			new -> next = NULL;
		}
		else
			*begin_list = new;
	}
}

void	push_front(t_stack **begin_list, t_stack *new)
{
	if (*begin_list)
	{
		new -> next = *begin_list;
		*begin_list = new;
	}
	else
		*begin_list = new;
}

int	is_sorted(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	if (stack)
	{
		while (node -> next != NULL)
		{
			if ((node -> content) > ((node -> next)-> content))
				return (0);
			node = node -> next;
		}
	}
	return (1);
}
