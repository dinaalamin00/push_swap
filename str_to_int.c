/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:34:52 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 14:35:28 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checksign(char c, int *i, int *sign)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	str_to_int(char **nptr, int index, t_stack **a)
{
	int			sign;
	long		result;
	int			i;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[index][i] == 32 || (nptr[index][i] >= 9
		&& nptr[index][i] <= 13))
		i++;
	checksign(nptr[index][i], &i, &sign);
	while (ft_isdigit(nptr[index][i]) && nptr[index][i])
		result = result * 10 + nptr[index][i++] - 48;
	if (nptr[index][i] != '\0')
	{
		ft_free(nptr);
		handle_error(a, NULL);
	}
	result = result * sign;
	if (result > INT_MAX || result < INT_MIN)
	{
		ft_free(nptr);
		handle_error(a, NULL);
	}
	return (result);
}
