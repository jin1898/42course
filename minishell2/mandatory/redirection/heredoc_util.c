/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 02:35:59 by jihham            #+#    #+#             */
/*   Updated: 2023/07/14 22:30:54 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_unlink(void)
{//   /tmp 디렉토리에서 확장자가 .mine인 파일을 찾아서(모든 엔트리를 다확인해서 엔트리 이름이 ".mine"인 엔트리를 찾는다.) 삭제하는 함수다.
	DIR				*directory;// 디렉토리를 나타내는 포인터
	struct dirent	*entry;
	char			*comma_pos;// 파일 이름에서 마지막 점 위치를 가리키는 포인터
	char			*join;  // 디렉토리 경로와 파일 이름을 결합한 문자열

	directory = opendir("/tmp");// "/tmp" 디렉토리 열기
	while (1)
	{
		entry = readdir(directory);// 디렉토리에서 엔트리 읽기(호출할 때마다 다음 엔트리를 읽어옴!) ->엔트리는 디렉토리 내의 파일 또는 서브디렉토리를 나타낸다.(directory에서 다음 파일 또는 디렉토리 엔트리를 읽어와서 entry에 저장)
		if (!entry)
			break ;// 모든 엔트리를 읽으면 반복문 종료(heredoc_unlink밖에 while(1)있음!)
		comma_pos = ft_strrchr(entry->d_name, '.');// 파일 이름에서 마지막 점 위치 찾기
		if (comma_pos && ft_strncmp(comma_pos, ".mine", 6) == 0)// ".mine" 확장자를 가진 파일인지 확인
		{
			join = ft_strjoin("/tmp/", entry->d_name);// 디렉토리 경로와 파일 이름을 결합한 문자열 생성
			unlink(join);// 결합한 경로에 해당하는 파일 삭제
			ft_free_util((void **)&join);// 동적 할당된 메모리 해제
		}
	}
	closedir(directory);//디렉토리 닫기
}

char	*get_heredoc_filename(int i)
{//히어독 리다이렉션에 사용될 파일이름 생성
	char	*temp;
	char	*result;
	char	*filenum;

	filenum = ft_itoa(i); //i를 문자열로 바꿔서 파일 넘버로 저장
	temp = ft_strjoin(filenum, ".mine"); //filenum과 .mine 합쳐주기
	ft_free_util((void **)&filenum);//필요없어진 filenum 없애버리기
	result = ft_strjoin("/tmp/", temp); //또 /tmp/ + temp해주기
	ft_free_util((void **)&temp);//필요없는거 free
	if (!result) //동적할당 실패했을시
		return (NULL); //널 가드 
	return (result); //파일 이름 반환 
}

int	new_heredoc_open(int i)
{// 히어독리다이렉션에 사용할 새파일디스크립터 열거나 생성 그리고 60줄에서 리다이렉션 사용될파일 이름 뽑아와서 같은 이름의 파일이 있을경우 파일삭제해버리기/ 그리고 open으로 파일생성하거나 열고 파일디스크립터 반환
	int		fd;
	char	*result;

	result = get_heredoc_filename(i); // 리다이렉션에 사용될 파일이름을 저장
	if (!result) // 리다이렉션에 사용될 파일 이름 실패시 
		return (-1); // 리턴 -1
	if (!access(result, F_OK)) // result파일에 접근가능한지확인, F_OK : 파일존재여부 확인
		unlink(result); //result라는 파일이 있을경우 파일 삭제
	fd = open(result, O_CREAT | O_RDWR | O_TRUNC, 0644); //result 파일 생성혹은 열고, 파일디스크립터 반환/O_CREAT 파일없을경우 파일생성해/O_RDWR 파일을 읽고 쓸수있게 파일열어/O_TRUNC : 파일열떄 내용을 비워/ 0644 : user에게읽기,쓰기권한부여, 기타 에게는 읽기권한만
	free(result); // result 바로 free
	return (fd);
}

int	heredoc_open(int i)
{
	int		fd;
	char	*result;

	result = get_heredoc_filename(i); //히어독파일이름 가져오기 
	if (!result) // 파일 이름 가져오지못할경우
		return (-1); // 리턴 -1
	fd = open(result, O_RDWR, 0644);// result이름의 파일을 읽기/쓰기 모드로 연다./0644 : user에게읽기,쓰기권한부여, 기타 에게는 읽기권한만
	free(result);//파일이름 저장용도이기때문에 이제 필요없음
	return (fd); // 파일디스크립트 리턴
}
