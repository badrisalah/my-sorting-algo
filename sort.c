/* ************************************************************************** */
/*										*/
/*							:::		::::::::   */
/*   sort.c			:+:   :+:	:+:   */
/*							+:+ +:+		+:+	*/
/*   By: sabadri <sabadri@student.42.fr>			+#+  +:+		+#+	*/
/*						+#+#+#+#+#+   +#+		*/
/*   Created: 2025/02/14 10:34:28 by sabadri			#+#  #+#			*/
/*   Updated: 2025/02/20 17:49:41 by sabadri			###   ########.fr	*/
/*										*/
/* ************************************************************************** */

#include "../push_swap.h"

void	sort3(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1] && stack->arr[1] > stack->arr[2])
	{
		sa(stack, 0);
		rra(stack, 0);
	}
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2]
		&& stack->arr[0] > stack->arr[2])
		rra(stack, 0);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2]
		&& stack->arr[0] > stack->arr[2])
	{
		rra(stack, 0);
		rra(stack, 0);
	}
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2]
		&& stack->arr[0] < stack->arr[2])
	{
		rra(stack, 0);
		sa(stack, 0);
	}
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2]
		&& stack->arr[0] < stack->arr[2])
		sa(stack, 0);
}

void	sort4(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = lst_min(a->arr, a->len);
	if (min_index > a->len / 2)
	{
		while (min_index < a->len)
		{
			rra(a, 0);
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			ra(a, 0);
			min_index--;
		}
	}
	pb(a, b, 0);
	sort3(a);
	pa(a, b, 0);
}

void	sort5(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = lst_min(a->arr, a->len);
	if (min_index > a->len / 2)
	{
		while (min_index < a->len)
		{
			rra(a, 0);
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			ra(a, 0);
			min_index--;
		}
	}
	pb(a, b, 0);
	sort4(a, b);
	rra(b, 0);
	pa(a, b, 0);
}

void	sort50(t_stack *a, t_stack *b, int chanksize)
{
	t_stack	sorted_arr;
	int		j;

	sorted_arr.arr = (int *)malloc(a->len * sizeof(int));
	arr_cpy(a->arr, &sorted_arr, a->len);
	sorted_arr.len = a->len;
	arr_sort(&sorted_arr, sorted_arr.len);
	c(a, b, &sorted_arr, chanksize);
	j = 0;
	while (j < b->len)
		pick_the_biggest(a, b, sorted_arr);
	free(sorted_arr.arr);
}
