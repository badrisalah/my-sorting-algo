/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 01:17:26 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/27 10:20:23 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_number(char *str, char **tmp)
{
	if (ft_strlen(str) == 1 || *str == '-' || *str == '+')
	{
		if (ft_strlen(str) == 1 && ((*str == '-' || *str == '+')
				|| !ft_isdigit(*str)))
			return (free_str(tmp), exit(1), 0);
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (free_str(tmp), exit(1), 0);
		str++;
	}
	return (1);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_dup(t_stack stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack.len)
	{
		j = i + 1;
		while (j < stack.len)
		{
			if (stack.arr[i] == stack.arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	fill_stack(char **a, t_stack *stack_a, int length)
{
	int		i;
	int		j;
	char	**split;
	char	**tmp;

	i = 1;
	j = 0;
	while (i < length)
	{
		(1) && (split = ft_split(a[i], ' '), tmp = split);
		if (!split)
			return (0);
		while (*split)
		{
			if (!is_number(*split, tmp))
				return (free_str(tmp), exit(1), 0);
			stack_a->arr[j] = ft_atoi(*split);
			(split)++;
			j++;
		}
		free_str(tmp);
		i++;
	}
	return (1);
}

int	check_args(char **a, int length)
{
	int		i;
	int		j;
	char	**split;
	char	**tmp;

	i = 1;
	j = 0;
	while (i < length)
	{
		split = ft_split(a[i], ' ');
		tmp = split;
		while (*split)
		{
			if (!is_number(*split, tmp) || atoif(*split) > 2147483647
				|| atoif(*split) < -2147483648)
				return (free_str(tmp), exit(1), 0);
			j++;
			(split)++;
		}
		free_str(tmp);
		i++;
	}
	return (j);
}
