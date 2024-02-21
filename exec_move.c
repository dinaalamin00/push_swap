/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:31:11 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 14:31:40 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	valid_move(char *move)
{
	if ((ft_strncmp("sa\n", move, ft_strlen(move)) == 0)
		|| (ft_strncmp("sb\n", move, ft_strlen(move)) == 0)
		|| (ft_strncmp("ss\n", move, ft_strlen(move)) == 0)
		|| (ft_strncmp("pa\n", move, ft_strlen(move)) == 0)
		|| (ft_strncmp("pb\n", move, ft_strlen(move)) == 0)
		|| (ft_strncmp("ra\n", move, ft_strlen(move)) == 0)
		|| (ft_strncmp("rb\n", move, ft_strlen(move)) == 0)
		|| (ft_strncmp("rr\n", move, ft_strlen(move)) == 0)
		|| (ft_strncmp("rra\n", move, ft_strlen(move)) == 0)
		|| (ft_strncmp("rrb\n", move, ft_strlen(move)) == 0)
		|| (ft_strncmp("rrr\n", move, ft_strlen(move)) == 0))
		return (1);
	return (0);
}

static int	check_swap(t_stack **a, t_stack **b, char *move)
{
	if (ft_strncmp("sa\n", move, ft_strlen(move)) == 0)
	{
		swap_elem(a, 0);
		return (1);
	}
	else if (ft_strncmp("sb\n", move, ft_strlen(move)) == 0)
	{
		swap_elem(b, 0);
		return (1);
	}
	else if (ft_strncmp("ss\n", move, ft_strlen(move)) == 0)
	{
		swap_elem(a, 0);
		swap_elem(b, 0);
		return (1);
	}
	return (0);
}

static int	check_rotate(t_stack **a, t_stack **b, char *move)
{
	if (ft_strncmp("ra\n", move, ft_strlen(move)) == 0)
	{
		rotate_list(a, 0);
		return (1);
	}
	else if (ft_strncmp("rb\n", move, ft_strlen(move)) == 0)
	{
		rotate_list(b, 0);
		return (1);
	}
	else if (ft_strncmp("rr\n", move, ft_strlen(move)) == 0)
	{
		rotate_list(a, 0);
		rotate_list(b, 0);
		return (1);
	}
	return (0);
}

static int	check_r_rotate(t_stack **a, t_stack **b, char *move)
{
	if (ft_strncmp("rra\n", move, ft_strlen(move)) == 0)
	{
		r_rotate_list(a, 0);
		return (1);
	}
	else if (ft_strncmp("rrb\n", move, ft_strlen(move)) == 0)
	{
		r_rotate_list(b, 0);
		return (1);
	}
	else if (ft_strncmp("rrr\n", move, ft_strlen(move)) == 0)
	{
		r_rotate_list(a, 0);
		r_rotate_list(b, 0);
		return (1);
	}
	return (0);
}

void	exec_move(t_stack **a, t_stack **b, char *move)
{
	while (valid_move(move))
	{
		if (check_swap(a, b, move))
			break ;
		if (check_rotate(a, b, move))
			break ;
		if (check_r_rotate(a, b, move))
			break ;
		if (ft_strncmp("pa\n", move, ft_strlen(move)) == 0)
		{
			push_elem(a, b, 0);
			break ;
		}
		else if (ft_strncmp("pb\n", move, ft_strlen(move)) == 0)
		{
			push_elem(b, a, 0);
			break ;
		}
	}
	if (!valid_move(move))
	{
		free(move);
		handle_error(a, b);
	}
	free(move);
}
