/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:12:54 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/19 06:05:31 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h> ////////////////////
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	shift_buff_or_clean_it(char *buff, size_t j);
int		has_the_end(char *buff, char **line);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstlast(t_list *lst);

#endif