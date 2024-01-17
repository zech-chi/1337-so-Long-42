/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:14:16 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:14:35 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			r;
	int			e;

	if (fd < 0 || fd >= OPEN_MAX)
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
