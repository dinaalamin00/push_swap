/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:48:15 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 17:02:14 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_move(t_stack **a, t_stack **b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		exec_move(a, b, move);
		move = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc > 1)
	{
		a = 0;
		b = 0;
		assign_args(&a, argc, argv);
		size = stack_size(a);
		apply_move(&a, &b);
		if (is_sorted(a) && stack_size(a) == size)
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
