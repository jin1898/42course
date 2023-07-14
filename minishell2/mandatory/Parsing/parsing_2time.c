/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:41:36 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/11 19:03:10 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	second_parsing_by_metacharacters(t_list **token_list, char *str) //token_list에 결과를 저장할것이다. str은 1차 토큰화된 값 1개이다.
{
	char	*buff;
	int		str_i;//str의 글자 위치 표시
	int		buf_i;//buff의 글자 위치 표시
	int		quote_flag;// 따옴표 플래그 ->홑따옴표인지 쌍따옴표인지 아스키코드로 저장

	str_i = 0;
	buf_i = 0;
	quote_flag = 0;
	buff = malloc(sizeof(char) * (ft_strlen(str) + 1)); //str의 갯수만큼 할당 ->새로운 토큰화 하더라도 str의 갯수를 넘길순없기때문에 최대 사이즈임을 알수있다.
	ft_bzero(buff, sizeof(char) * (ft_strlen(str) + 1));
	while (str[str_i]) //토큰 1개를 한글자씩 돌아가면서 다시 파씽
	{
		if (buf_i && !quote_flag && check_new_token(str, str_i, buff))//1글자이상이고, 따옴표 안쪽이 아니고, 파이프 리다이렉션 종류이면 토큰화 ->buf_i가 참이라는것은 적어도 한글자 이후부터 새로운 토큰으로 자르겠다는 뜻이다.
			create_buff_put_end_of_list(buff, &buf_i, token_list);// token_list에 새로운토큰을 넣어주기
		if (!quote_flag && (str[str_i] == '\'' || str[str_i] == '\"'))//따옴표 발견시 어떤 따옴표인지 저장(플래그)
			quote_flag = str[str_i];
		else if (quote_flag == str[str_i]) //따옴표의 짝이 맞는다면 (맞을수밖에없다 1차 가공때 에러는 다 처리함) 플래그 0
			quote_flag = 0;
		buff[buf_i] = str[str_i]; //31번째줄 조건에 맞지 않으면 버퍼에 넣어서 31번 조건에 걸리거나 41번에서 토큰화 시켜주기
		buf_i++; //37에서 저장했으니 한칸옮기기
		str_i++; //다음 글자 비교하기위해 한칸옮기기
	}
	create_buff_put_end_of_list(buff, &buf_i, token_list);//마지막 토큰화를 위하여 장치걸어주기
	ft_free_util((void **)&buff);// 필요없는 buff free
}

void	create_buff_put_end_of_list(char *buff, int *buf_i, t_list **token_list)
{
	buff[*buf_i] = '\0'; //글자 마지막에 널 넣어주기 
	ft_lstadd_back(token_list, ft_lstnew(ft_strdup(buff))); //토큰화 한걸 token_list의 노드로 넣어주기
	ft_bzero(buff, ft_strlen(buff) + 1); // 반드시!!!!!! 0으로 초기화해줘야함buff재활용하는중
	*buf_i = 0;
}

int	check_new_token(char *str, int jdx, char *buff) //여기서 토큰화될 추가 문자들 
{
	if (str[jdx] == '|')
		return (1);
	else if (str[jdx] == '<') //str이 < 인데 buff(이전에 str담겨있던 문자)가 < 라면 그냥 <이아니라 <<이기 때문에 나누면 큰일남 
	{
		if (!ft_strncmp(buff, "<", 2))
			return (0);// 그렇기 때문에 buff에 <<가 짤리지 않게 토큰화 안하도록 0리턴
		return (1);
	}
	else if (str[jdx] == '>')//str이 > 인데 buff(이전에 str담겨있던 문자)가 > 라면 그냥 >이아니라 >>이기 때문에 나누면 큰일남 
	{
		if (!ft_strncmp(buff, ">", 2))
			return (0); // 그렇기 때문에 buff에 >>가 짤리지 않게 토큰화 안하도록 0리턴
		return (1);
	}
	if (check_redir(buff) || !ft_strncmp(buff, "|", 2)) //buff값이 리다이렉션이거나 파이프일경우 당연히 토큰화를 해야 한개의 노드로써 리다이렉션과 파이프가 들어감.
		return (1);
	return (0);
}

static void	init_vlaue(t_list **spl_list, int *start_i, int *line_i, int *quote_flag)
{
	*spl_list = NULL;
	*start_i = 0;
	*line_i = -1;
	*quote_flag = 0;
}
static void	cmpar_i(int *start_i, char **line, int *line_i, t_list **spl_list)
{
	if (*start_i != *line_i)
		ft_lstadd_back(spl_list, ft_lstnew(\
		ft_substr(*line, *start_i, *line_i - *start_i))); // 한토큰으로써 spl_list에 (start_i부터 넣기
	*start_i = *line_i + 1;
}

t_list	*first_parsing_by_space(char *line)
{
	t_list	*spl_list; //결과적으로 리턴할 연결리스트 1차 파씽 결과넣을것이다.
	int		start_i; // line의 시작위치와
	int		line_i; // line의 검사위치이다.
	int		quote_flag; // 따옴표 플래그

	init_vlaue(&spl_list, &start_i, &line_i, &quote_flag); //그냥 변수 초기화하는 거다. norm때문에 ㅠㅠ
	while (line[++line_i])// 입력받은 값의 문자 하나하나를 모두 확인한다.
	{
		if (!quote_flag && check_space(line[line_i])) //(따옴표가 아니고) (탭이랑 스페이스 일때만) -> 탭과 스페이스를 제외하고 다른 특수 문자가 들어오는것을 막기위함이다.
			cmpar_i(&start_i, &line, &line_i, &spl_list); // 99의 조건을 만족할시 한 토큰으로써 판단하고 (start_i부터 line_i까지)토큰화하기
		else if (!quote_flag && (line[line_i] == '\"' || line[line_i] == '\'')) // 첫 따옴표들이 들어올경우 플래그로 해당따옴표(쌍따옴표든 홑따옴표든) 아스키번호 넣어주기
			quote_flag = line[line_i];
		else if (quote_flag == line[line_i]) // 따옴표의 짝을 만날시 플래그 0으로 바꾸기
			quote_flag = 0;
	}
	if (quote_flag) // quote_flag는 반드시 한쌍의 따옴표가 모여야 에러로 판단하지 않는다. 하지만 while문이 끝난뒤에 quote_flag가 양수라는건 따옴표의 짝이 맞지않다는 뜻이다. 
	{
		ft_printf(1, "minishell: syntax error: unexpected end of file\n"); //따옴표한개는 에러라는 뜻이다.
		g_exit_status = 258;//따옴표 에러 번호저장.
		return (NULL);
	}
	if (start_i != line_i) //만약 두 변수의 값이 같지 않다는 뜻은 마지막 토큰화될 값이 추가되지 않았다는 것을 의미.
		ft_lstadd_back(&spl_list, ft_lstnew(\
		ft_substr(line, start_i, line_i - start_i))); // 마지막 토큰을 리스트에 추가해주기 
	return (spl_list); // 결론 띄어쓰기 와 따옴표를 기준으로 1차 파씽 완료.
}

t_list	*splitting_values_into_tokens(char *line) // 평가자가 입력한 값을 line으로 가져옴
{
	t_list	*token_list; //임시로 파씽한 부분을 저장할곳1 (파이프/리다이렉션 기준으로 파씽된 2차 가공품을 저장)
	t_list	*spl_list; //임시로 파씽한 부분을 저장할곳2 (스페이스 기준으로 파씽된 1차 가공품을 저장)
	t_list	*spl_cur; //while을 돌기위한 헤드 대신 할 변수

	token_list = NULL;
	spl_list = NULL;
	spl_list = first_parsing_by_space(line);//스페이스 기준으로 1차로 파씽하는 곳
	if (spl_list == NULL) // 에러가 있을시 함수를 바로 빠져나간다.
		return (NULL);
	spl_cur = spl_list; // 1차 파씽한 구조체의 헤드를 받아온다.
	while (spl_cur) // 헤드를 받아와서 모든 노드를 다시 한번더 (리다이렉션/ 파이프)기준으로 파씽한다. -> 리다이렉션과 파이프를 만나면 한 노드로 다시 생성
	{
		second_parsing_by_metacharacters(&token_list, (char *)(spl_cur->content)); //파이프 리다이렉션기준으로 1차 가공된 파씽을 2차로 또가공
		spl_cur = spl_cur->next; //현재노드는 토큰화가 완료되었으니 다음 노드도 토큰하기 위해서 다음으로 이동
	}
	free_list1(&spl_list); // 어짜피 1차2차 가공된 총 연결리스트는 token_list임으로 필요가 없어진 연결리스트는 바로 free해주기
	return (token_list); // 결과적으로 띄어쓰기, 파이프, 리다이렉션기준으로 나뉜 결과를 리턴
}
