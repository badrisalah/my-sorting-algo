/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:40:09 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/27 10:18:59 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 50000

typedef struct push_swap
{
	int		*arr;
	int		len;
}			t_stack;

int			is_dup(t_stack stack);
int			is_number(char *str, char **tmp);
int			check_args(char **a, int length);
int			ft_error(char *s);
void		free_str(char **str_array);
int			fill_stack(char **av, t_stack *a, int ac);
char		**ft_split(char *s, char c);
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(char *str);

void		sorting_algo(t_stack *a, t_stack *b);
void		sort3(t_stack *a);
void		sort4(t_stack *a, t_stack *b);
void		sort5(t_stack *a, t_stack *b);
void		sort50(t_stack *a, t_stack *b, int chanksize);

void		pick_the_biggest(t_stack *a, t_stack *b, t_stack sarr);

void		arr_cpy(int *arr, t_stack *sarr, int len);
void		lst_push(int *arr, int value, int len);
int			lst_min(int *arr, int length);
void		arr_sort(t_stack *sarr, int len);
void		c(t_stack *a, t_stack *b, t_stack *sorted_arr, int chanksize);
int			get_index(t_stack sa, int x);
int			find_largest_index(t_stack *b, int largest);
int			find_largest(t_stack *b);
int			choose(t_stack *b);

void		sa(t_stack *a, int x);
void		sb(t_stack *b, int x);
void		ss(t_stack *a, t_stack *b, int x);
void		pa(t_stack *a, t_stack *b, int x);
void		pb(t_stack *a, t_stack *b, int x);
void		ra(t_stack *a, int x);
void		rb(t_stack *a, int x);
void		rra(t_stack *a, int x);
void		rrb(t_stack *b, int x);
void		rr(t_stack *a, t_stack *b, int x);
void		rrr(t_stack *a, t_stack *b, int x);

char		*get_next_line(int fd);
int			already_sorted(t_stack *a);
long long	atoif(char *str);
int			ft_isdigit(char c);
int			ft_strlen(char *str);
char		*ft_strdup(char *s1);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, int start, int len);
char		*ft_strchr(char *s, int c);
int			check_moves(t_stack *a, t_stack *b);

#endif