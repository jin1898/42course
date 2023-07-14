/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:12:50 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/12 20:52:53 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

char	*connect_list(t_list *list)
{// 연결리스트를 하나의 단어로 만드는 작업!
	char	*text;
	t_list	*cur;
	int		len;

	len = 0;
	cur = list;
	while (cur)
	{
		len += ft_strlen((char *)(cur->content));
		cur = cur->next;
	}
	text = malloc(sizeof(char) * (len + 1));
	ft_bzero(text, sizeof(char) * (len + 1));
	cur = list;
	while (cur)
	{
		ft_strlcat(text, (char *)(cur->content), len + 1);
		cur = cur->next;
	}
	return (text);
}

static char	*ft_pexitstatus(int *str_i)
{
	char	*str;

	if (str_i)
		*str_i += 1;
	str = ft_itoa(g_exit_status);
	g_exit_status = 0;
	return (str);
}
static char	*ft_find_cur(t_env *cur, char *substr, int len, char **status_num)
{
	char	*str;

	while (cur)
	{
		if (!strncmp(substr, cur->key, len) && cur->key[len] == '\0')
		{
			if (*status_num && cur->value)
			{
				str = ft_strjoin(cur->value, *status_num);
				ft_free_util((void **)status_num);
				return (str);
			}
			if (cur->value && !ft_free_util((void **)status_num))
				return (ft_strdup(cur->value));
		}
		cur = cur->next;
	}
	return (NULL);
}
char	*expand_env(char *substr, int *str_i, t_env_manager *env_lst)
{
	t_env	*cur;
	int		len;
	char	*status_num;
	char	*result;

	if (substr[0] == '?') // $?일경우 exit넘버를 출력해줘야함!
		return (ft_pexitstatus(str_i));
	len = 0;
	status_num = NULL;
	while (ft_isalpha(substr[len]) || ft_isalnum(substr[len]))
		len++;
	if (str_i)
		*str_i += len;
	cur = env_lst->head;
	result = ft_find_cur(cur, substr, len, &status_num);
	if (result)
		return (result);
	if (ft_isdigit(substr[0]))
		return (ft_substr((substr + 1), 0, ft_strlen(substr + 1) - 1));
	if (substr[0] == '\0' || (substr[ft_strlen(substr)-1] == '\"'))
		return (ft_strdup("$"));
	ft_free_util((void **)&status_num);
	return (ft_strdup(""));
}

static void	init_value(t_value *value, char *str, t_list **text_list)
{
	value->str_i = 0;
	value->buf_i = 0;
	*text_list = NULL;
	value->q_flag = 0;
	value->quote = 0;
	value->ex_f = 0;
	value->buff = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_bzero(value->buff, (ft_strlen(str) + 1));
}


// static void	ft_quote_check(t_value *value, char *str, t_list **text_list, int *q_flag)
// {
// 	if (!value->quote_flag && (str[value->str_i] == '\'' || str[value->str_i] == '\"'))
// 	{
// 		create_buff_put_end_of_list(value->buff, &value->buf_i, text_list);
// 		if (str[value->str_i] == '"')
// 			*q_flag = 1;
// 		value->quote_flag = str[value->str_i];
// 	}
// 	else if (value->quote_flag == str[value->str_i])
// 	{
// 		create_buff_put_end_of_list(value->buff, &value->buf_i, text_list);
// 		value->quote_flag = 0;
// 	}
// }
// static void	ft_expand_buffcheck(char *str, t_value *value, t_list **text_list, t_env_manager *env_lst)
// {
// 	if (str[value->str_i] == '$' && (value->quote_flag != '\''))
// 	{
// 		create_buff_put_end_of_list(value->buff, &value->buf_i, text_list);
// 		ft_lstadd_back(text_list, ft_lstnew(expand_env(str + value->str_i + 1, &value->str_i, env_lst)));
// 		value->ex_f = 1;
// 	}
// 	else
// 		value->buff[value->buf_i++] = str[value->str_i];
// 	value->str_i++;
// }

static void	ft_str_check(char *str, t_value *value, t_list **text_list, t_env_manager *env_lst)
{
	while (str[value->str_i])
	{
		if (!value->quote && (str[value->str_i] == '\'' || str[value->str_i] == '\"')) //따옴표시작부분일때
		{
			create_buff_put_end_of_list(value->buff, &value->buf_i, text_list); //따옴표시작부분전을 연결리스트에 넣어주기 
			if (str[value->str_i] == '"')//확장부분때문에 flag로 토큰화를 한번더하려고 넣음.
				value->q_flag = 1;
			value->quote = str[value->str_i];// 따옴표 플래그 넣어주기
		}
		else if (value->quote == str[value->str_i]) //따옴표의 짝을 찾았다면
		{
			create_buff_put_end_of_list(value->buff, &value->buf_i, text_list); // 따옴표끝난 부분을 연결리스트에 넣어주기
			value->quote = 0; //따옴표 플래그 없애주기
		}
		else if (str[value->str_i] == '$' && (value->quote != '\'')) //확장을 해야하는 부분인지 확인 ->작은따옴표는 확장을해줘야함 '$USER' == jsunwoo
		{
			create_buff_put_end_of_list(value->buff, &value->buf_i, text_list);//확장부분은 따로 저장을 해줘야하기때문에 이전 토큰은 연결리스트에 저장
			ft_lstadd_back(text_list, ft_lstnew(\
			expand_env(str + value->str_i + 1, &value->str_i, env_lst)));//확장해야할부분을 확장후 한토큰으로 넣어주기 
			value->ex_f = 1; //으악  필요없는부분이 아직도 남아있네
		}
		else
			value->buff[value->buf_i++] = str[value->str_i]; //조건문에 걸리지 않는것들은 buff에 넣어서 저장해주기
		value->str_i++;//다음 글자로 넘어가기
	}
}

char	*replace_symbol_to_text(char *str, t_env_manager *env_lst, t_value *value)
{// str이 리다이렉션의 파일명을 넣어하는지/ argv에 넣어야하는지/here_doc인지 판단후 넣기
	t_list	*text_list;
	char	*word;

	init_value(value, str, &text_list); //놈때문에 초기화
	ft_str_check(str, value, &text_list, env_lst); //str을 이제 따옴표,확장일때에 따라서 변경해주기
	create_buff_put_end_of_list(value->buff, &value->buf_i, &text_list); //ft_str_check에서 마지막으로 처리되지 않은 value->buff에 남아있는 값이 있다면 같이넣어주기
	ft_free_util((void **)&value->buff);//buff는 필요없으니 바로 free해주기
	if (value->q_flag == 1 && value->redir != 1) //str이 리다이렉션 파일명이 아닐경우!
	{
		word = connect_list(text_list); //연결리스트를 한단어로 만들기 
		free_list1(&text_list); //연결리스트 free
		value->text = ft_strjoin("\"", word); //***이거 플래그이다. 나중에 한번더 쓰는걸로 기억함!
		ft_free_util((void **)&word); //word는 필요없으니까 바로 free
	}
	else
	{
		value->text = connect_list(text_list);//파일명, here_doc일경우 바로 연결해서 돌려주기
		free_list1(&text_list);
	}
	return (value->text); // 무조건 연결리스트가 아닌 한글자로 나감.
}

int	check_mbgos(char *str, t_value *value, t_env_manager *env_lst) //str은 현재 값!
{
	char	c = ' ';
	char	*s = str;
	int		i = 0;
	int		word;

	value->mbgos = 0;
	word = 0;
	if (str[i] == '$') // $가 있다는건 확장 가능성이있다는 뜻.
	{
		value->mbgos = 1; //s에서 할당되어나오니 free를 해주기 위한 flag
		s = expand_env(str + 1, &value->str_i, env_lst);
	}
	value->s_c = s;
	while (*s)
	{
		if (*s != c && (*(s + 1) == '\0' || *(s + 1) == c))
			word++;
		s++;
	}
	if (value->mbgos == 1)
		free(value->s_c);
	return (word);
}

static int	ft_redir(t_redir **redir_now, t_list **token_now, \
t_value *value, t_env_manager *env_lst)
{
	int	check_ambiguous;

	check_ambiguous = 0;
	value->redir = 1; // 후에 플래그로 리다이렉션임을 나타내야함
	(*redir_now)->type = redir_type((*token_now)->content);//리다이렉션의 타입을 가져오기
	(*token_now) = (*token_now)->next; //리다이레션 뒤에는 파일명이들어오기 때문에 다음으로 넘어가서 확인해봐야함.
	check_ambiguous = check_mbgos((*token_now)->content, value, env_lst); //엠지시어스를 확인.
	if ((*redir_now)->type != HERE_DOC && !check_ambiguous) // 히어독이 아닐경우
	{
		(*redir_now)->str = \
		replace_symbol_to_text((*token_now)->content, env_lst, value); //확장과 따옴표처리해서 한글자로 옴.
	}
	else
		(*redir_now)->str = ft_strdup((*token_now)->content);//here_doc이아닐경우 그냥 바로 복사
	return (check_ambiguous);
}

static void	word_etc(t_cmd_info **cmd_info_arr_now, t_value *value, t_list *token_now, t_env_manager *env_lst)
{
	(*cmd_info_arr_now)->argv[value->av_i] = \
	replace_symbol_to_text(token_now->content, env_lst, value);
	value->av_i += 1;
}

static void	ft_pip(t_value *value, t_cmd_info \
**cmd_info_arr_now, t_redir **redir_now) // | 단위로 구조체를 만들었기 때문에 다음 구조체를 넘기는 작업하기
{
	value->av_i = 0; // av의 갯수 초기화 
	(*cmd_info_arr_now) = (*cmd_info_arr_now)->next; // 다음 노드로 이동 
	(*redir_now) = (*cmd_info_arr_now)->redir; //다음 노드의 리다이렉션으로 이동
}

void	fill_cmd_info_arr(t_cmd_info *cmd_info_arr, \
t_list *token_list, t_env_manager	*env_lst)
{
	t_list		*token_now;
	t_value		value;
	t_redir		*redir_now;
	t_cmd_info	*cmd_info_arr_now;

	token_now = token_list;
	value.av_i = 0; //argv현재 번호
	value.cmd_i = 0; //헐 이거 필요없는것같은데
	value.redir = 0; //현재 token_now->content가 리다이렉션인가? 에 대한 플래그
	cmd_info_arr_now = cmd_info_arr;
	redir_now = cmd_info_arr_now->redir;
	while (token_now)
	{
		if (!ft_strncmp(token_now -> content, "|", 2)) 
			ft_pip(&value, &cmd_info_arr_now, &redir_now); // | 일경우 다음 구조체로 이동해주기
		else if (check_redir(token_now -> content))
		{
			if ((ft_redir(&redir_now, &token_now, &value, env_lst) > 1) && value.mbgos == 1) //리다이렉션 중에서 엠비시어스작업만 따로 조건문으로 줬다.
				cmd_info_arr_now->redir->type = 'a';//엠비시어스일경우 리다이렉션 표시를 a로 바꿔주기
			redir_now = redir_now->next; // 다음 리다이렉션으로 이동
		}
		else
			word_etc(&cmd_info_arr_now, &value, token_now, env_lst); //argv의 단어로 판단, 따옴표나 확장부분을 변경해서 argv에 넣기 
		token_now = token_now -> next;// 다음으로 넘긴다.
	}
}

char	**split_token(char **a)
{
	t_list	*split;
	t_list	*s_cpy;
	int		count;
	char	**result;

	split = first_parsing_by_space(a[0]);
	s_cpy = split;
	count = 0;
	while (s_cpy)
	{
		count++;
		s_cpy = s_cpy->next;
	}
	result = malloc(sizeof(char *) * count);
	s_cpy = split;
	count = 0;
	while (s_cpy)
	{
		result[count] = s_cpy->content;
		count++;
		s_cpy = s_cpy->next;
	}
	return (result);
}
