/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:50:55 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/23 20:06:40 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_error(char *s)
{
	write(1, s, ft_strlen(s));
	return (1);
}

void	free_str(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}

int	lst_min(int *arr, int len)
{
	int	min_index;
	int	i;
	int	j;

	min_index = 0;
	i = 0;
	j = 0;
	while (i < len)
	{
		if (arr[i] < arr[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	lst_push(int *arr, int value, int len)
{
	int	i;

	if (len >= 1)
	{
		i = 0;
		while (len)
		{
			len--;
			arr[len + 1] = arr[len];
		}
	}
	arr[len] = value;
}
