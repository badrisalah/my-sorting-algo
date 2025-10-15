/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:10:50 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/27 10:13:49 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	do_instruction(t_stack *a, t_stack *b, char *instraction)
{
	if (!ft_strcmp(instraction, "sa"))
		sa(a, 69);
	else if (!ft_strcmp(instraction, "sb"))
		sb(b, 69);
	else if (!ft_strcmp(instraction, "ss"))
		ss(a, b, 69);
	else if (!ft_strcmp(instraction, "pa"))
		pa(a, b, 69);
	else if (!ft_strcmp(instraction, "pb"))
		pb(a, b, 69);
	else if (!ft_strcmp(instraction, "ra"))
		ra(a, 69);
	else if (!ft_strcmp(instraction, "rb"))
		rb(b, 69);
	else if (!ft_strcmp(instraction, "rr"))
		rr(a, b, 69);
	else if (!ft_strcmp(instraction, "rra"))
		rra(a, 69);
	else if (!ft_strcmp(instraction, "rrb"))
		rrb(b, 69);
	else if (!ft_strcmp(instraction, "rrr"))
		rrr(a, b, 69);
}

int	isvalid_instruction(char *str)
{
	if (ft_strcmp(str, "sa") && ft_strcmp(str, "sb") && ft_strcmp(str, "ss")
		&& ft_strcmp(str, "pa") && ft_strcmp(str, "pb") && ft_strcmp(str, "ra")
		&& ft_strcmp(str, "rb") && ft_strcmp(str, "rr") && ft_strcmp(str, "rra")
		&& ft_strcmp(str, "rrb") && ft_strcmp(str, "rrr"))
		return (0);
	return (1);
}

int	check_moves(t_stack *a, t_stack *b)
{
	char	*buffer;
	char	**instr;

	while (1)
	{
		buffer = get_next_line(0);
		if (!buffer || !*buffer)
		{
			free(buffer);
			return (1);
		}
		instr = ft_split(buffer, '\n');
		free(buffer);
		if (instr && isvalid_instruction(instr[0]))
		{
			do_instruction(a, b, instr[0]);
			free_str(instr);
		}
		else
		{
			free_str(instr);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	b.len = 0;
	if (argc == 1)
		return (0);
	a.len = check_args((char **)argv, argc);
	if (!a.len)
		return (ft_error("error"));
	a.arr = (int *)malloc(sizeof(int) * a.len);
	b.arr = (int *)malloc(sizeof(int) * a.len);
	if (!a.arr || !b.arr)
		return (ft_error("error"));
	if ((!fill_stack((char **)argv, &a, argc) || is_dup(a)))
		return (ft_error("error"));
	if (!check_moves(&a, &b))
		return (ft_error("Error"));
	if (already_sorted(&a) && !b.len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a.arr);
	free(b.arr);
	return (0);
}
