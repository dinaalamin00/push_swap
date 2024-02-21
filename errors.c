/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:58:48 by diahmed           #+#    #+#             */
/*   Updated: 2024/01/27 16:48:01 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *lst)
{
	int		cnt;
	t_stack	*temp;

	temp = lst;
	cnt = 0;
	while (temp)
	{
		cnt++;
		temp = temp -> next;
	}
	return (cnt);
}

char	*join(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s2)
		return (NULL);
	ptr = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	**ft_free(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (ptr);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = NULL;
	if (*stack && stack)
	{
		while (*stack)
		{
			temp = (*stack)-> next;
			free(*stack);
			*stack = NULL;
			*stack = temp;
		}
	}
}

void	handle_error(t_stack **a, t_stack **b)
{
	ft_putendl_fd("Error", 2);
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	exit (EXIT_FAILURE);
}
