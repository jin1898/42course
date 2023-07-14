// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   trash.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/05/30 20:05:15 by jsunwoo           #+#    #+#             */
// /*   Updated: 2023/06/15 15:20:09 by jsunwoo          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"
// //해당 함수들은 제출시 지워야하는 함수임으로 놈규칙을 지키지 않아도된다.


// void	print_t_list(t_list *a) //지워야하는함수
// {
// 	for(t_list *b = a; b; b=b->next)
// 		ft_printf(1, "[%s] ",b->content);
// 	ft_printf(1, "\n");
// }

// void	print(void *ptr) //지워야하는함수
// {
// 	char	*str;

// 	str = (char *)ptr;
// 	ft_printf(1, "[%s] ", str);
// }

// void	print_cmd_arr(t_cmd_info *cmd_info_arr, int pipe_num) //지워야하는함수
// {
// 	(void)pipe_num;
// 	ft_printf(1, "------------파씽구조체담긴정보---start-----------\n");
// 	while(cmd_info_arr)
// 	{
// 		ft_printf(1, "argc: %d\n", cmd_info_arr->argc);
// 		ft_printf(1, "argv: ");
// 		for (int j = 0; cmd_info_arr->argv && cmd_info_arr->argv[j] ; j++)
// 			ft_printf(1, "[%s] ", cmd_info_arr->argv[j]);
// 		ft_printf(1, "\n");
// 		ft_printf(1, "pipe_num: %d", cmd_info_arr->pipe_num);
// 		ft_printf(1, "\n");
// 		ft_printf(1, "redir_num: %d\n", cmd_info_arr->redir_num);
// 		ft_printf(1, "redir: ");
// 		for (t_redir*a = cmd_info_arr->redir; a && a->type;a = a->next)
// 		{
// 			char *redirection;
// 			switch (a->type)
// 			{
// 				case INFILE:
// 					redirection = "<";
// 					break;
// 				case OUTFILE:
// 					redirection = ">";
// 					break;
// 				case HERE_DOC:
// 					redirection = "<<";
// 					break;
// 				case FILE_APPEND:
// 					redirection = ">>";
// 					break;
// 				case AMBIGUOUS:
// 					redirection = "a";
// 					break;
// 			}
// 			ft_printf(1, "[%s, %s] ", redirection, a->str);
// 		}
// 		ft_printf(1, "\n----------------파씽구조체담긴정보---end------------\n");
// 		cmd_info_arr = cmd_info_arr->next;
// 	}
// }
