/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_ut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:35:08 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/22 20:39:14 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	arr_cpy(int *arr, t_stack *sarr, int len)
{
	while (len--)
		sarr->arr[len] = arr[len];
}

void	arr_sort(t_stack *sarr, int len)
{
	int	i;
	int	swapped;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		swapped = 0;
		j = 0;
		while (j < len - i - 1)
		{
			if (sarr->arr[j] > sarr->arr[j + 1])
			{
				temp = sarr->arr[j];
				sarr->arr[j] = sarr->arr[j + 1];
				sarr->arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

void	force_rrb(t_stack *b, int number)
{
	while (b->arr[0] != number)
		rrb(b, 0);
}

void	force_rb(t_stack *b, int number)
{
	while (b->arr[0] != number)
		rb(b, 0);
}

void	pick_the_biggest(t_stack *a, t_stack *b, t_stack sarr)
{
	int	largest;
	int	index;

	sarr = *b;
	largest = find_largest(b);
	index = find_largest_index(b, largest);
	if (index <= b->len / 2)
		force_rb(b, largest);
	else
		force_rrb(b, largest);
	pa(a, b, 0);
}
