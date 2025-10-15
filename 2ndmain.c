/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ndmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:41:09 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/27 10:19:29 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	process_split(char **split, t_stack *stack, int *j)
{
	long long	val;
	char		**tmp;

	tmp = split;
	while (*split)
	{
		if (!is_number(*split, tmp))
		{
			free_str(tmp);
			return (0);
		}
		val = atoif(*split);
		if (val > 2147483647 || val < -2147483648)
		{
			free_str(tmp);
			return (0);
		}
		stack->arr[*j] = val;
		(*j)++;
		split++;
	}
	free_str(tmp);
	return (1);
}

long long	atoif(char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}
