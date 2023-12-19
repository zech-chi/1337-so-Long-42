/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:11:36 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/19 01:12:09 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			r;
	int			e;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	line = NULL;
	if (has_the_end(buff, &line))
		return (line);
	r = read(fd, buff, BUFFER_SIZE);
	e = has_the_end(buff, &line);
	while (r > 0 && e == 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		e = has_the_end(buff, &line);
	}
	if (r == -1 || e == -1 || (line && ft_strlen(line) == 0))
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
