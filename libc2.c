/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:04:36 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/25 00:11:08 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	frr(char **s, int i)
{
	while (i > 0)
	{
		free(s[i - 1]);
		i--;
	}
	free(s);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int	get_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static char	**re(const char *s, char c, char **res, size_t i)
{
	size_t	y;

	while (s && *s)
	{
		y = 0;
		while (*s == c)
			s++;
		if (!*s)
			break ;
		res[i] = (char *)malloc((get_len(s, c) + 1) * sizeof(char));
		if (!res[i])
		{
			frr(res, i);
			return (NULL);
		}
		while (*s && *s != c)
			res[i][y++] = *s++;
		res[i][y] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char *s, char c)
{
	char	**res;
	size_t	i;

	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	return (re(s, c, res, i));
}
