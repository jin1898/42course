/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:09:15 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/01/12 19:26:43 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_box
{
	int				fd;
	int				read_rlt;
	char			*back;
	struct s_box	*next;
}t_box;

char	*get_next_line(int fd);
int		ft_strfind(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2, \
size_t s1_len, size_t s2_len);
char	*subline(t_box **fd_node, t_box **head);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);
t_box	*add_node(t_box **head, int fd);
char	*del(t_box	**head, int fd);
t_box	*ft_find(int fd, t_box **head);
char	*read_result(int fd, char *buffer, t_box **fd_node, t_box **head);

#endif
