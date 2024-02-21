/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:30:33 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 17:03:24 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		assign_args(&a, argc, argv);
		if (is_sorted(a))
		{
			free_stack(&a);
			exit (EXIT_SUCCESS);
		}
		if (stack_size(a) == 2)
			swap_elem(&a, 'a');
		else if (stack_size(a) == 3)
			mini_sort(&a);
		else
			sort(&a, &b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
