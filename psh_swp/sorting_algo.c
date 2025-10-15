/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:15:51 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/25 02:25:36 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	already_sorted(t_stack *a)
{
	int	i;
	int	ans;

	i = 0;
	ans = 0;
	if (!a->len)
		return (0);
	while (i < a->len - 1)
	{
		if (a->arr[i] < a->arr[i + 1])
			ans++;
		i++;
	}
	if (ans != i)
		return (0);
	return (1);
}

void	sorting_algo(t_stack *a, t_stack *b)
{
	b->len = 0;
	if (already_sorted(a))
	{
		write(1, "\n", 1);
		return ;
	}
	if (a->len == 2)
		sa(a, 0);
	else if (a->len == 3)
		sort3(a);
	else if (a->len == 4)
		sort4(a, b);
	else if (a->len == 5)
		sort5(a, b);
	else if (a->len <= 100)
		sort50(a, b, 16);
	else
		sort50(a, b, 34);
}

int	get_index(t_stack sa, int x)
{
	int	i;

	i = 0;
	while (i < sa.len)
	{
		if (sa.arr[i] == x)
			return (i);
		i++;
	}
	return (0);
}

int	choose(t_stack *b)
{
	int	i;
	int	max;

	i = 0;
	max = INT_MIN;
	while (i < b->len)
	{
		if (b->arr[i] > max)
			max = b->arr[i];
		i++;
	}
	return (max);
}
