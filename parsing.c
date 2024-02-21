/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:22:32 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 15:57:22 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_dup(t_stack *stack, int x)
{
	t_stack	*node;

	node = stack;
	if (node)
	{
		while (node)
		{
			if (x == node -> content)
				return (1);
			node = node -> next;
		}
	}
	return (0);
}

static int	is_space(char c)
{
	if ((c == 32 || (c >= 9 && c <= 13))
		|| (c == '+' || c == '-'))
		return (1);
	return (0);
}

static int	strdig(const char *str)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && cnt == 0)
			cnt = 1;
		else if (!ft_isdigit(str[i]) && !is_space(str[i]))
			return (0);
		i++;
	}
	if (cnt == 1)
		return (1);
	return (0);
}

static void	assign_stack(t_stack **a, char *elems)
{
	char	**splitted;
	int		i;

	splitted = ft_split(elems, 32);
	free(elems);
	if (!splitted || !splitted[0])
		exit(EXIT_FAILURE);
	i = 0;
	while (splitted[i])
	{
		if (is_dup(*a, str_to_int(splitted, i, a)))
		{
			ft_free(splitted);
			handle_error(a, NULL);
		}
		push_back(a, create_elem(a, str_to_int(splitted, i, a)));
		i++;
	}
	ft_free(splitted);
}

void	assign_args(t_stack **a, int argc, char **argv)
{
	int		i;
	char	*elems;
	char	*temp;

	i = 1;
	elems = NULL;
	while (i < argc)
	{
		if (strdig(argv[i]))
		{
			temp = join(elems, argv[i]);
			free(elems);
			elems = join(temp, " ");
			free(temp);
		}
		else
		{
			ft_putendl_fd("Error", 2);
			if (elems)
				free(elems);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	assign_stack(a, elems);
}
