/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:14:49 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/26 19:45:45 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_databox
{
	int		h_flag;
	char	**path;
	char	*fd_boxs;
}	t_db;

int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *s1, char split_word);
char	**shape_word(char **ret, char *s1, char split_word);
void	free_arr(char ***ret, char **ret2);
void	what_parameter(char **argv, int argc, t_db *db);
int		find_path(char **envp, t_db *db);
void	error_message(char *s);
int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
