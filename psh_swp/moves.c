/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:25:50 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/25 00:27:38 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a, int x)
{
	int	tmp;

	if (a->len >= 2)
	{
		tmp = a->arr[0];
		a->arr[0] = a->arr[1];
		a->arr[1] = tmp;
		if (x != 69)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b, int x)
{
	int	tmp;

	if (b->len >= 2)
	{
		tmp = b->arr[0];
		b->arr[0] = b->arr[1];
		b->arr[1] = tmp;
		if (x != 69)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b, int x)
{
	sa(a, x);
	sb(b, x);
	if (x != 69)
		write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b, int x)
{
	int	i;

	i = 1;
	if (b->len)
	{
		lst_push(a->arr, b->arr[0], a->len);
		while (i < b->len)
		{
			b->arr[i - 1] = b->arr[i];
			i++;
		}
		b->arr[--i] = 0;
		(a->len)++;
		(b->len)--;
		if (x != 69)
			write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b, int x)
{
	int	i;

	i = 1;
	if (a->len)
	{
		lst_push(b->arr, a->arr[0], b->len);
		while (i < a->len)
		{
			a->arr[i - 1] = a->arr[i];
			i++;
		}
		(b->len)++;
		(a->len)--;
		if (x != 69)
			write(1, "pb\n", 3);
	}
}
