/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:16:05 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/22 17:43:24 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a, int x)
{
	int	i;
	int	tmp;

	i = 0;
	if (a->len > 1)
	{
		tmp = a->arr[0];
		while (i + 1 < a->len)
		{
			a->arr[i] = a->arr[i + 1];
			i++;
		}
		a->arr[i] = tmp;
		if (x != 69)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stack *b, int x)
{
	int	i;
	int	tmp;

	if (b->len > 1)
	{
		i = 0;
		tmp = b->arr[0];
		while (i + 1 < b->len)
		{
			b->arr[i] = b->arr[i + 1];
			i++;
		}
		b->arr[i] = tmp;
		if (x != 69)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack *a, t_stack *b, int x)
{
	ra(a, x);
	rb(b, x);
	if (x != 69)
		write(1, "rr\n", 3);
}

void	rra(t_stack *a, int x)
{
	int	tmp;
	int	i;
	int	len;

	len = a->len;
	if (len > 1)
	{
		i = 1;
		tmp = a->arr[(len)-- - 1];
		while (len)
		{
			a->arr[len] = a->arr[len - 1];
			i++;
			(len)--;
		}
		a->arr[0] = tmp;
		if (x != 69)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *b, int x)
{
	int	tmp;
	int	i;
	int	len;

	len = b->len;
	if (len > 1)
	{
		i = 1;
		tmp = b->arr[len-- - 1];
		while (len)
		{
			b->arr[len] = b->arr[len - 1];
			i++;
			len--;
		}
		b->arr[0] = tmp;
		if (x != 69)
			write(1, "rrb\n", 4);
	}
}
