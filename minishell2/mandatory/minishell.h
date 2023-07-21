/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihham <jihham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:23:59 by jihham            #+#    #+#             */
/*   Updated: 2023/05/28 18:50:26 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define READLINE_LIBRARY

# include <libft.h>
# include <ft_printf.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "readline.h"
# include "history.h"
# include <unistd.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>

enum	e_redir
{
	INFILE = 1,
	HERE_DOC,
	OUTFILE,
	FILE_APPEND,
	AMBIGUOUS = 97,
};

typedef struct s_redir {
	int				type;
	char			*str;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd_info
{
	int					argc;
	char				**argv;
	int					pipe_num;
	int					redir_num;
	t_redir				*redir;
	int					in_fd;
	int					out_fd;
	int					here_doc_cnt;
	int					is_redir_error;
	struct s_cmd_info	*next;
}	t_cmd_info;

typedef struct s_exec_info
{
	t_cmd_info	*cmd_info;
}	t_exec_info;

enum	e_opt {
	ARGC,
	REDIR,
	HERE,
};

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}t_env;

typedef struct s_env_manager
{
	t_env	*head;
	int		size;
}t_env_manager;

typedef struct s_value
{
	int					av_i;
	int					cmd_i;
	struct s_cmd_info	*cmd_info_arr;
	char				*text;
	char				*buff;
	int					re_i;
	int					str_i;
	int					buf_i;
	int					q_flag;
	int					quote;
	int					mbgos;
	int					redir;
	char				*s_c;
}t_value;

// built_in.c
int			put_str(char *s, int fd);
int			is_ignore_first_arg(char *arg);

// builtin ft_*.c
int			ft_cd(char **args, t_env_manager *env_manager);
int			ft_echo(char **args);
int			ft_env(t_env_manager *env_manager);
int			ft_exit(char **args);
int			ft_export(char **args, t_env_manager *env_manager);
int			ft_pwd(void);
int			ft_unset(char **args, t_env_manager *env_manager);

// env_convert_util.c
int			is_exist_oldpwd(char *key);
int			check_shlvl(t_env *env);

// env_convert.c
int			env_arr_to_list(t_env_manager *env_manager, char **envp);
char		**env_list_to_arr(t_env_manager *env_manager);

// env_key.c
int			is_valid_env_key(char *key);
int			get_key_value(char *arg, char **key, char **value);

// env_node_manager.c
t_env		*get_last_node(t_env *head);
t_env		*make_node(char *key, char *value);

// env_node.c
t_env		*make_env(char *arg);
int			add_env(t_env_manager *env_manager, t_env *new_env);
int			delete_env(t_env_manager *env_manager, char *key);
t_env		*get_env(t_env *env, char *key);
int			change_env_value(t_env_manager *env_manager, \
char *key, char *value);

// free_exit.c
void		free_for_exit(t_env_manager *env_manager, int code);
int			free_node(t_env **node);
int			free_env(t_env_manager *env_manager);

// excute.c
int			run_built_in(t_cmd_info *cmd_arr, t_env_manager *env_manager);
int			ft_execution(t_cmd_info *cmd_arr, t_env_manager *env_manager);
void		run_execve(t_cmd_info *cmd_arr, t_env_manager *env_manager);

// excution_path.c
char		*get_path(t_env *env, char *av);

// execution_redir.c
int			ft_redirection(t_cmd_info *cmd_arr, \
t_env_manager *env_manager, int *is_sigint);

// heredoc_util.c
void		heredoc_unlink(void);
void		heredoc_child_check(char *delimiter, \
int fd, t_env_manager *env_manager);
char		*get_heredoc_filename(int i);
int			new_heredoc_open(int i);
int			heredoc_open(int i);

// redirection.c
int			ft_output(char *outfile);
int			ft_input(char *infile);
int			ft_heredoc(char *delimiter, int i, \
t_env_manager *env_manager, int *is_sigint);
int			ft_append(char *outfile);

// signal_handler.c
void		newline_ctrl_c(int signum);
void		heredoc_ctrl_c(int signum);
void		ctrl_c(int signum);

// signal.c
void		set_child_signal(void);
void		set_parent_ignore_signal(void);
void		set_heredoc_signal(void);
void		set_signal_parent(void);
void		set_signal(void);

// util
int			ft_perror_join(char *prefix, char *postfix);
int			ft_perror(char *cause);
int			is_unsigned_num(char *arg);
int			is_num(char *arg);
int			ft_free_util(void **target);

// execute_multiple_pipe.c
int			execute_multiple_pipe(t_cmd_info *cmd_arr, \
t_env_manager *env_manager);
int			execute_single_pipe(t_cmd_info *cmd_arr, \
t_env_manager *env_manager);

// child_exit_status.c
int			check_exit_status(int child_status, int *signum);

//parsing_overall_structure.c [파씽 전체 과정이 담겨있는 파일]
t_cmd_info	*parsing_allparts(char *line, t_env_manager	*env_manager);
int			get_pipnum(t_list *token_list);
int			check_space(char ch);//int			is_space(char ch);
int			redir_type(char *str);//int			get_type(char *str);
char		**ft_slice(char *str, char sep);
// void		print_command_line_prompt(void);

//parsing_2time.c [파씽하는 파트 넣어둠.]
t_list		*splitting_values_into_tokens(char *line);
t_list		*first_parsing_by_space(char *line);
void		second_parsing_by_metacharacters(t_list **token_list, char *str);
void		create_buff_put_end_of_list(char *buff, \
int *buf_i, t_list **token_list);
int			check_new_token(char *str, int jdx, char *buff);

//get_cmd_info.c
t_cmd_info	*cmd_arr_init(t_list **token_list, int pipe_num);
int			init_cmd_info(t_cmd_info *cmd_info, int cnt[]);
int			check_redir(char *str);
void		print_token_err(char *str, t_cmd_info *cmd_info_arr);
t_cmd_info	*make_to_list(t_cmd_info **list, int num);

//cmd_arr.c
void		fill_cmd_info_arr(t_cmd_info *cmd_info_arr, \
t_list *token_list, t_env_manager	*env_lst);
char		*replace_symbol_to_text(char *str, t_env_manager \
*env_lst, t_value *value);
char		*expand_env(char *substr, int *str_i, t_env_manager *env_lst);
char		*connect_list(t_list *list);

// t_cmd_info	*split_lasttime(t_cmd_info*struc);
t_cmd_info	*make_to_list_cmdinfo(int num);
t_redir		*make_to_list_redir(int num);
char		*dele_space_tab(char *str);
char		**split_token(char **a);
int			ft_putargv(char **cmd, t_value *value, char *word);

//파씽확인하는 함수
int			check_mbgos(char *str, t_value *value, t_env_manager *env_lst);
void		free_for_exit(t_env_manager *env_manager, int code);
int			expand_count(char *str, char c);
void		parsing_command(t_cmd_info *cmd, char *path);
char		**cut_token(char *argv, t_list **list);
void		free_list1(t_list**list_all);
void		free_eveything(char **line, t_cmd_info **cmd_arr);
char		**merge_token(t_list *list_all);
void		put_path(char **argv, char *path);
t_list		*split_space(char *line);

#endif
