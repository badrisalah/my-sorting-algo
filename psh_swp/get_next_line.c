/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabadri <sabadri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:49:28 by sabadri           #+#    #+#             */
/*   Updated: 2025/02/21 18:34:34 by sabadri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*fill_line_buffer(int fd, char *line, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(line);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		if (!line)
			line = ft_strdup("");
		tmp = line;
		line = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

static char	*extract_line(char *line_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!line_buffer || !*line_buffer)
		return (NULL);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	line = ft_substr(line_buffer, 0, i + 1);
	return (line);
}

static char	*set_remainder(char *line_buffer)
{
	size_t	i;
	char	*remainder;

	i = 0;
	if (!line_buffer)
		return (NULL);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (!line_buffer[i])
	{
		free(line_buffer);
		return (NULL);
	}
	remainder = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i - 1);
	free(line_buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, line, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	str = extract_line(line);
	line = set_remainder(line);
	return (str);
}
