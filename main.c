/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 01:11:28 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/27 09:38:37 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_largest(t_stack *b)
{
	int	largest;
	int	current;
	int	i;

	largest = choose(b);
	i = 1;
	while (i < b->len)
	{
		current = choose(b);
		if (current > largest)
			largest = current;
		i++;
	}
	return (largest);
}

int	find_largest_index(t_stack *b, int largest)
{
	int	j;
	int	index;

	index = 0;
	j = 0;
	while (j < b->len)
	{
		if (b->arr[j] == largest)
		{
			index = j;
			break ;
		}
		j++;
	}
	return (index);
}

void	c(t_stack *a, t_stack *b, t_stack *sorted_arr, int chanksize)
{
	int	j;
	int	k;
	int	index;

	j = 0;
	k = a->len;
	while (j < k)
	{
		index = get_index(*sorted_arr, a->arr[0]);
		if (index <= j)
		{
			pb(a, b, 0);
			j++;
		}
		else if (index <= j + chanksize)
		{
			pb(a, b, 0);
			rb(b, 0);
			j++;
		}
		else
			ra(a, 0);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		return (ft_error("error"));
	a.len = check_args(av, ac);
	if (a.len != 0)
	{
		a.arr = (int *)malloc(sizeof(int) * a.len);
		b.arr = (int *)malloc(sizeof(int) * a.len);
		if (!a.arr || !b.arr)
			return (ft_error("error"));
		if (!fill_stack(av, &a, ac))
			return (ft_error("error"));
		if (is_dup(a))
			return (free(a.arr), free(b.arr), ft_error("error"));
		sorting_algo(&a, &b);
		free(a.arr);
		free(b.arr);
	}
	else
		return (ft_error("error"));
}
