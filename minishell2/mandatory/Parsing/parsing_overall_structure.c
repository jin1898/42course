/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_overall_structure.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:38:10 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 18:01:39 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	get_pipnum(t_list *token_list)
{
	t_list	*cur;
	int		pipe_num;

	cur = token_list;
	pipe_num = 0;
	while (cur)
	{
		if (!ft_strncmp(cur->content, "|", 2))
			pipe_num += 1;
		cur = cur -> next;
	}
	return (pipe_num);
}

int	check_space(char ch)
{
	if (ch == ' ' || ch == '\t')
		return (1);
	return (0);
}

void	print_token_err(char *str, t_cmd_info *cmd_info_arr)
{
	free_eveything(0, &cmd_info_arr); //모든것을 free해주기
	if (!strncmp(str, "|", 2))
		str = " `|\'";
	ft_printf(1, "minishell: syntax error near unexpected token %s\n", str); //에러메세지를 화면에 출력
	g_exit_status = 258; // 에러 번호 입력
}

int	redir_type(char *str)
{
	if (!ft_strncmp(str, "<", 2))
		return (INFILE);
	if (!ft_strncmp(str, "<<", 3))
		return (HERE_DOC);
	if (!ft_strncmp(str, ">", 2))
		return (OUTFILE);
	if (!ft_strncmp(str, ">>", 3))
		return (FILE_APPEND);
	return (0);
}

static int	ft_slice_count(char *str, char sep, int *sep_idx)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			*sep_idx = i;
			break ;
		}
		i++;
	}
	return (i);
}

char	**ft_slice(char *str, char sep)
{
	char	**strs;
	size_t	i;
	int		sep_idx;
	size_t	str_len;

	sep_idx = 0;
	str_len = ft_strlen(str);
	i = ft_slice_count(str, sep, &sep_idx);
	if (i == str_len)
		return (0);
	strs = (char **)malloc(sizeof(char *) * 3);
	if (!strs)
		return (NULL);
	strs[2] = 0;
	strs[0] = (char *)malloc(sizeof(char) * (sep_idx));
	strs[1] = (char *)malloc(sizeof(char) * (str_len - sep_idx + 1));
	ft_strlcpy(strs[0], str, sep_idx + 1);
	ft_strlcpy(strs[1], str + sep_idx + 1, str_len - sep_idx);
	return (strs);
}

t_cmd_info	*parsing_allparts(char *line, t_env_manager *env_lst)
{
	int			pipe_num;//파이프 갯수
	t_list		*token_list; //파씽결과를 잠시 저장할곳
	t_cmd_info	*cmd_info_arr; // 최종 파씽결과를 넣을 곳
	t_cmd_info	*temp; //while문을 돌기위한 헤드부분대신할 변수

	token_list = splitting_values_into_tokens(line); //나눠야할 모든부분(띄어쓰기/파이프/리다이렉션)을 나눔
	if (token_list == NULL) // 에러가 있을시 널을 리턴(즉 에러로인해 파씽부분을 종료하기위한 코드)
		return (NULL);
	pipe_num = get_pipnum(token_list);//파이프 갯수를 얻어내는 곳
	cmd_info_arr = cmd_arr_init(&token_list, pipe_num); // 109줄에서 자른 파씽의 정보를 갖고 구조체를 할당초기화.
	if (cmd_info_arr == NULL) //에러가 있는지 확인
	{
		free_list1(&token_list); //에러가 있을시 리스트를 free해주기
		return (NULL);//널종료를 보내서 다음 실행문이 돌아가지 않게하기
	}
	fill_cmd_info_arr(cmd_info_arr, token_list, env_lst); // 113에서 할당 초기화한 구조체에다가 정보에 맞게 채워넣기
	free_list1(&token_list); // 정보로 넘길 구조체가 완성되었으니 임시로 사용하던 리스트는 free해주기
	temp = cmd_info_arr;
	while (temp) // 최종본구조체마다 파이프 갯수를 다 넣어주기
	{
		temp->pipe_num = pipe_num;
		temp = temp->next;
	}
	// print_cmd_arr(cmd_info_arr, pipe_num);
	// system("leaks --list -- minishell");
	return (cmd_info_arr); //최종 구조체 리턴
}
