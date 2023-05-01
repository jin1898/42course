/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:14:49 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/05/01 22:43:07 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct s_databox
{
	int		h_flag;
	char	**path;
	char	*fd_boxs;
	int		outfilenum;
	int		infilenum;
	int		*pipebox;
	int		cmdnum;
	int		error_flag;
	char	*cmd;
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
void	here_doc(char *eof, t_db *db);
int		ft_strcmp2(char *s1, char *s2, int a);
void	make_and_open_pipe(int argc, t_db *db);
void	make_child(t_db *db, char **argv, char **envp);
void	excute_cmd(int idx, char **argv, t_db *db, char **envp);
void	start_child(t_db *db, int cmd_sequence, char **argv, char **envp);
void	pipe_close(t_db	*db);
char	*find_cmd(char	**path, char *cmd, t_db *db);
void	free_everything(t_db *db);
void	close_and_wait(t_db	*db);
void	excute_cmd2(int idx, char **argv, t_db *db);
void	check_cmd(char **argv, int argc, t_db *db);
void	p_error_2(t_db *db);
#endif
