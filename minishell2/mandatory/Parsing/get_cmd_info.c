/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:53:23 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/21 18:01:09 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_status;

int	check_redir(char *str) // 어떤 리다이렉션인지 찾는것
{
	if (!ft_strncmp(str, "<", 2))
		return (1);
	if (!ft_strncmp(str, "<<", 3))
		return (1);
	if (!ft_strncmp(str, ">", 2))
		return (1);
	if (!ft_strncmp(str, ">>", 3))
		return (1);
	return (0);
}

int	init_cmd_info(t_cmd_info *cmd_info, int cnt[])
{
	cmd_info->argc = cnt[ARGC]; // 토큰화될 인자의 갯수 (리다이렉션은 제외)
	if (cnt[ARGC])
	{
		cmd_info->argv = malloc(sizeof(char *) * (cnt[ARGC] + 1)); // 토큰 갯수만큼 할당해주기
		ft_memset(cmd_info->argv, 0, (sizeof(*cmd_info->argv) * cnt[ARGC])); //할당해준것 값에 맞게 0으로 초기화
		cmd_info->argv[cnt[ARGC]] = NULL; // 마지막에 널넣어주기
	}
	cmd_info->redir_num = cnt[REDIR]; //리다이렉션 숫자 구조체에 넣어주기
	if (!cmd_info->redir_num) // 리다이렉션이 감지되지 않았으면
		cmd_info->redir = NULL; // 널로 초기화
	else
		cmd_info->redir = make_to_list_redir(cnt[REDIR]); // 리다이렉션을 위한 연결리스트를 만들어서 구조체와 연결해주기
	cnt[ARGC] = 0; //재활용을 위한 배열 초기화
	cnt[REDIR] = 0; // 재활용을 위한 배열 초기화
	return (1);
}

t_cmd_info	*make_to_list_cmdinfo(int num)
{
	int			i;
	t_cmd_info	*now;
	t_cmd_info	*head;

	i = 0;
	head = (t_cmd_info *)malloc(sizeof(t_cmd_info));
	ft_memset(head, 0, sizeof(t_cmd_info));
	now = head;
	while (i < num)
	{
		now->next = (t_cmd_info *)malloc(sizeof(t_cmd_info));
		now = now->next;
		ft_memset(now, 0, sizeof(t_cmd_info));
		i++;
	}
	now->next = NULL;
	return (head);
}

t_redir	*make_to_list_redir(int num)
{
	int		i;
	t_redir	*head;
	t_redir	*now;

	head = (t_redir *)malloc(sizeof(t_redir)); //리다이렉션 담을 연결리스트 헤드 할당
	now = head;
	i = 1;
	ft_memset(head, 0, sizeof(t_redir)); //헤드 0으로 초기화
	while (i < num) // num갯수만큼 연결리스트 만들기
	{
		now->next = (t_redir *)malloc(sizeof(t_redir));
		now = now->next;
		ft_memset(now, 0, sizeof(t_redir));
		i++;
	}
	now->next = NULL;// 마지막표시를 위하여 NULL넣기
	return (head); // 리다이렉션을 위한 연결리스트를 리턴해주기
}

static int	redir_error(int cnt[], t_list **token_now, t_cmd_info *cmd_info_arr)
{
	cnt[REDIR] += 1; //리다이렉션이기 때문에 들어온것이다. 그러니 리다이렉션 갯수++
	(*token_now) = (*token_now) -> next;
	if ((*token_now) == NULL || check_redir((*token_now) -> content) || !ft_strncmp((*token_now) -> content, "|", 2)) //이미 파씽다한시점에서 리다이렉션이나 파이프가 오면 안됨! 널도 안됨! 이 모든 것을 에러로 판단함!
	{
		if ((*token_now) == NULL) //리다이렉션 뒤에 널이 들어가면 안됨!
			ft_printf(1, "minishell: syntax error near unexpected token `newline'\n"); //에러출력
		else
			print_token_err((*token_now) -> content, cmd_info_arr); //해당 에러 출력 및 모두 free
		return (0);
	}
	else
		return (1); // 에러없으면 1로 리턴
}

static int	error_check(t_list **token_now, t_cmd_info \
**cmd_info_arr, t_list **token_list) //파이프 다음에 오면 안되는 에러상황들 걸러내기
{
	if ((*token_now)->next == NULL) // | 다음에 널이 오면 에러
	{
		print_token_err(" `|\'", *cmd_info_arr);
		free_list1(token_list); // 바로 리스트를 free해주기
		return (0);
	}
	else if (((*token_now)->next == 0) || \
	(!ft_strncmp((*token_now)->next->content, "|", 2))) //****** | 다음에 |가 또와서는 안됨
	{
		print_token_err(" `|\'", *cmd_info_arr);
		free_list1(token_list);
		return (0);
	}
	else if (!ft_strncmp((*token_list)->content, "|", 2)) //****** 원본의 값이 | 면안됨
	{
		print_token_err(" `|\'", *cmd_info_arr);
		free_list1(token_list);
		return (0);
	}
	else
		return (1);
}

static void	init_var(int cnt[], t_cmd_info **cmd_info_arr, t_cmd_info **cmd_now, int pipe_num)
{
	cnt[ARGC] = 0;
	cnt[REDIR] = 0;
	*cmd_info_arr = make_to_list_cmdinfo(pipe_num);
	*cmd_now = *cmd_info_arr;
}

t_cmd_info	*cmd_arr_init(t_list **token_list, int pipe_num) // 1차2차파씽완료한 연결리스트와 파이프 갯수를 넘겨받음
{
	t_cmd_info	*cmd_info_arr;
	t_list		*token_now;
	t_cmd_info	*cmd_now;
	int			cnt[2]; //그냥 놈때문에 나눠서 편하게 저장. argc , redir갯수 저장함

	token_now = *token_list; // while문돌때 헤드 대신하는 변수로 사용
	init_var(cnt, &cmd_info_arr, &cmd_now, pipe_num); //놈때문에 초기화 코드만 따로 뺌
	while (token_now) //1차2차파씽완료한 연결리스트의 노드 1개씩 돌아가면서 초기화 해야할 요소를 확인
	{
		if (!ft_strncmp(token_now -> content, "|", 2)) // 파이프 단위로 구조체를 만들어줄것이기때문에 파이프일시 구조체 한개 만들기
		{
			init_cmd_info(cmd_now, cnt); // 지금까지 모은 정보로 구조체 만들기
			cmd_now = cmd_now->next; // 다음노드로 넘어가주기
			if (!error_check(&token_now, &cmd_info_arr, token_list)) //파이프 이후(현재노드)의 토큰에 따라서 에러처리할게좀있음
				return (NULL);
		}
		else if (check_redir(token_now -> content) && \
		(!redir_error(cnt, &token_now, cmd_info_arr))) // 현재가 리다이렉션일때 다음 글자들이 에러인지 판단
			return (NULL);
		else
			cnt[ARGC] += 1; //리다이렉션이 아닐때 명령어 혹은 출력 인자로 판단하여 argc++ (구조체를 보면 알수 있지만 리다이렉션과 리다이렉션아닌것[argv]로 나뉘어져있음)
		token_now = token_now->next; // 다음토큰으로 넘어가기
	}
	init_cmd_info(cmd_now, cnt); //while문을 다돌고 마지막것들은 밖에서 구조체초기화 해주기
	return (cmd_info_arr); //파씽을 담을 구조체를 모두 갯수에 맞게 초기화후 리턴
}
