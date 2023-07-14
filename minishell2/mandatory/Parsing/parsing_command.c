/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:53:38 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/07/12 20:44:41 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_list(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
char	**merge_token(t_list *list_all)
{
	char	**answer;
	int		i;

	i = -1;
	answer = malloc(sizeof(char *) * (ft_count_list(list_all) + 1)); //연결리스트의 갯수만큼 말록해주기 argv로 사용할 예정
	answer[ft_count_list(list_all)] = 0;// 마지막엔 NULL로 채워주기
	while (list_all)
	{
		answer[++i] = ft_strdup(list_all->content);//각 i번째 argv에 노드값을 넣어주기
		list_all = list_all->next;
	}
	return (answer);//연결리스트를 argv의 배열로 바꿔서 리턴함.
}

void	free_list1(t_list**list_all) //리스트를 모두 free해주는것
{
	t_list	*temp; //현재꺼랑 다음꺼 둘다 저장할꺼 필요해서 현재꺼 저장용도로 변수 선언
	while (*list_all)
	{
		temp = *list_all; // free할 현재꺼 저장
		*list_all = (*list_all)->next;// free할 다음꺼 저장
		ft_free_util((void **)&temp->content); // 현재노드 free하기
		// free(temp->content);
		ft_free_util((void **)&temp); //현재 주소도 free
		// free(temp);
	}
	*list_all = NULL;
}

void	free_list2(t_list **list, char **chr)
{
	ft_free_util((void **)&list);
	// free(*list);
	*list = NULL;
	ft_free_util((void **)&chr);
	// free(*chr);
	*chr = NULL;
}

int	find_colon(char *str, int idx)
{
	int	len;

	len = idx;
	while (str[len] && str[len] != ':')
		len++;
	return (len);
}
int	check_builtin(char **argv)
{
	if (ft_strncmp(argv[0], "cd", 3) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "echo", 5) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "pwd", 4) == 0)
		return (0);
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		return (0);
	else
		return (1);
}

static char	**ft_free(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (0);
}

static void access_change(int *i, char **s_path, char **argv)
{
	char	*temp;
	char	*temp1;
	while (s_path[++(*i)])
	{
		temp = ft_strjoin(s_path[*i], "/");
		temp1 = ft_strjoin(temp, argv[0]);
		free(temp);
		if (access(temp1, X_OK | F_OK) == 0)
		{
			free(argv[0]);
			argv[0] = temp1;
			break ;
		}
		else
			free(temp1);
	}
}
void	put_path(char **argv, char *path)
{
	char	**s_path;

	int		i;
	i = -1;
	if (argv[0] && !*argv[0])
		return ;
	if (*argv && check_builtin(argv))
	{
		s_path = ft_split(path, ':');
		access_change(&i, s_path, argv);
		ft_free(s_path);
	}
}

static void split_init(t_list **spl_list, int *start_i, int *line_i, int *quote_flag)
{
	*spl_list = NULL;
	*start_i = 0;
	*line_i = 0;
	*quote_flag = 0;
}
static void quote_do(int *start_i, int line_i, t_list **spl_list, char *line)
{
	if ((*start_i) != line_i)
		ft_lstadd_back(spl_list, ft_lstnew(\
		ft_substr(line, (*start_i), line_i - (*start_i))));
	(*start_i) = line_i + 1;
}
static void add_back(t_list	**spl_list, int line_i, int start_i, char *line)
{
	ft_lstadd_back(spl_list, ft_lstnew(\
	ft_substr(line, start_i, line_i - start_i)));
}
t_list	*split_space(char *line)
{
	t_list	*spl_list;
	int		start_i;
	int		line_i;
	int		quote_flag;

	split_init(&spl_list, &start_i, &line_i, &quote_flag);
	while (line[line_i])
	{
		if (!quote_flag && check_space(line[++line_i]))
		{
			if (start_i != line_i)
				ft_lstadd_back(&spl_list, ft_lstnew(\
				ft_substr(line, start_i, line_i - start_i)));
			start_i = line_i + 1;
		}
		else if (!quote_flag && (line[line_i] == '\"' || line[line_i] == '\''))
			quote_flag = line[line_i];
		else if (quote_flag == line[line_i])
			quote_flag = 0;
	}
	if (quote_flag)
		quote_do(&start_i, line_i, &spl_list, line);
	if (start_i != line_i)
		add_back(&spl_list, line_i, start_i, line);
	return (spl_list);
}

static char	*del_front_space(char *str)
{
	int		i;
	char	*word;
	int		word_i;

	word_i = 0;
	word = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!word)
		return (NULL);
	ft_memset(word, 0, ft_strlen(str) + 1);
	word[ft_strlen(str)] = '\0';
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		word[word_i] = str[i];
		word_i++;
		i++;
	}
	return (word);
}
void	parsing_newlist(char *str, t_list **list_all)
{
	t_list	*token_list;
	t_list	*list;
	char	*word;

	if (str[0] != 0)
	{
		if (str[0] != '\"')//cmd_arr.c:182에 대한 플래그다. 플래그가 없을시 실행된다.
		{
			word = del_front_space(str);// 앞에 공백이 있을시 공백을 없애준다.
			token_list = split_space(word); // 공백을 기준으로 나누어준다.
			ft_lstadd_back(list_all, token_list); //토큰을 나눈 연결리스트와 전체 연결리스트와 연결해준다.
			list = ft_lstlast(*list_all); 
			list->next = NULL;// 마지막에 널넣어준다.
		}
		else // 추가 적인 파씽이 필요없을때 실행됨
		{
			ft_lstadd_back(list_all, ft_lstnew(ft_strdup(str + 1))); //+1은 플래그를 때고 온전한 토큰만 가져가기 위함이다. ["ls -al]-> [ls -al]
			list = ft_lstlast(*list_all);
			list->next = NULL;// 마지막에 널넣는다.
		}
	}
}

void	parsing_command(t_cmd_info *cmd, char *path)
{//1번째 명령어에 대한 path를 넣어주기
	t_cmd_info	*cmd_c;
	int			i;
	t_list		*list_all;

	cmd_c = cmd;
	list_all = NULL;
	while (cmd_c)
	{
		i = -1;
		{
			while (cmd_c->argv && cmd_c->argv[++i])//argv를 한개씩 빼주기
			{
				parsing_newlist(cmd_c->argv[i], &list_all);// 파씽한번더해야하는지 판단후 필요시 파씽한번더하기
				free(cmd_c->argv[i]); //기존 argv free해주고 
				cmd_c->argv[i] = NULL; // 널넣어주기
			}
			free(cmd_c->argv);//argv를 전부 free해주기
			cmd_c->argv = merge_token(list_all); //argv를 연결리스트의 값을 넣어 다시만들기
			put_path(cmd_c->argv, path);// 첫번째 명령어만 path랑 같이 붙여버리기
			cmd_c = cmd_c->next;
			free_list1(&list_all);//필요없어진 list free해주기
		}
	}
	free(path);// path도 free해주기 
}
