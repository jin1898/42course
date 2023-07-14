/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:52:15 by jihham            #+#    #+#             */
/*   Updated: 2023/07/14 20:23:41 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	set_parent_ignore_signal(void)
{ //부모프로세스에서 시그널 처리 무시하는 함수 (부모 프로세스는 Ctrl+C Ctrl+\ 입력을 무시하고 계속 실행)
	signal(SIGINT, SIG_IGN);// SIGINT 시그널을 무시하도록 설정 (Ctrl+C 입력 무시)
	signal(SIGQUIT, SIG_IGN);// SIGQUIT 시그널을 무시하도록 설정 (Ctrl+\ 입력 무시)
}

void	set_child_signal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	set_heredoc_signal(void)
{
	signal(SIGINT, heredoc_ctrl_c);//(SIGINT:(ctrl+c:인터럽트시그널/프로그램종료시킴))을 눌렀을시 heredoc_ctrl_c 함수를 실행해줘 
	signal(SIGQUIT, SIG_IGN); //(SIGQUIT:(ctrl+\:(종료시그널))을(SIG_IGN:시그널무시함)해라
}

void	set_signal_parent(void)
{//부모프로세스에서 현재 함수가 작동할시 시그널을 무시하도록 설정
//why? : 자식프로세스 SIGINT SIGQUIT를 입력할시 자식프로세스의 동작을 방해받을 수있기 때문에 부모프로세스에서 해당 시그널을 막아주는것으로 예상
	signal(SIGINT, SIG_IGN);//(SIGINT : (ctrl+c :프로그램을 종료시킴/인트럽트 시그널)입력)을 (SIG_IGN : 시그널을 무시하는 매크로)해라.
	signal(SIGQUIT, SIG_IGN);//(SIGQUIT : (ctrl + \:프로그램을 종료시킴/종료시그널)입력)을 (SIG_IGN : 시그널을 무시하는 매크로)해라.
}

void	set_signal(void)
{//터미널 속성을 변경하고, 시그널 핸들러를 설정하여 Ctrl+C 시그널을 처리하는 기능을 만든다.
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term); // 현재 터미널 속성을 가져옴
	term.c_lflag &= ~ECHOCTL;// ECHOCTL 플래그 비트를 끄는 것으로, 컨트롤 문자를 출력하지 않도록 설정 (터미널 속성변경을 위한 과정)
	tcsetattr(STDIN_FILENO, TCSANOW, &term);// 변경된 터미널 속성을 설정
	signal(SIGINT, ctrl_c);// SIGINT (Ctrl+C) 시그널 핸들러를 ctrl_c로 설정
	signal(SIGQUIT, SIG_IGN);// SIGQUIT (Ctrl+\) 시그널은 무시 (무시되는 시그널은 기본 동작으로 처리됨)
	/*
	======================
	공부
	터미널 속성을 변경한다는 것은 터미널의 동작 방식이나 표시 방법을 제어하는 매개변수를 수정하는 것을 의미한다. 
	터미널 속성은 사용자 입력 및 출력에 대한 제어, 텍스트 표시 방식, 특수 문자 처리 등과 관련된 설정들을 포함한다.

	set_signal 함수에서 tcgetattr 함수를 사용하여 현재 터미널의 속성을 가져온 후, term.c_lflag 필드에서 ECHOCTL 플래그 비트를 끄는 작업을 수행한다. 
	ECHOCTL 플래그는 컨트롤 문자를 출력할 때 해당 문자를 보여줄지 여부를 제어하는 플래그로, 이를 비활성화하여 컨트롤 문자가 화면에 표시되지 않도록 설정한다.
	
	마지막으로 tcsetattr 함수를 사용하여 변경된 터미널 속성을 설정한다. 
	이를 통해 터미널의 동작 방식이나 표시 방법이 수정되고, 사용자 입력에 대한 처리가 변경될 수 있다.
	따라서 set_signal 함수는 터미널 속성을 조정하여 원하는 동작 방식과 표시 방법을 설정하는 역할을 한다.
	=======================
	52줄 공부 
	`term.c_lflag &= ~ECHOCTL;`는 `term` 변수의 `c_lflag` 필드에서 `ECHOCTL` 비트를 끄는 작업을 수행하는 코드다.
	`term.c_lflag`은 `struct termios` 구조체의 멤버로서, 터미널의 로컬 플래그(local flags)를 나타낸다. 
	`c_lflag`은 터미널 동작과 관련된 로컬 플래그들을 비트로 표현하는 비트 필드다.
	`ECHOCTL`은 로컬 플래그 중 하나로, 컨트롤 문자를 에코(출력)할 때 해당 문자를 표시할지 여부를 제어하는 비트다. 
	즉, `ECHOCTL` 비트가 켜져있으면 컨트롤 문자가 터미널 화면에 출력되고, 꺼져있으면 표시되지 않는다.
	`term.c_lflag &= ~ECHOCTL;`는 `ECHOCTL` 비트를 끄기 위해 비트 연산자를 사용한다. 
	`~ECHOCTL`는 `ECHOCTL`의 비트를 반전시킨 값을 나타내며, `&=` 연산자를 사용하여 `term.c_lflag`와 비트를 AND 연산하여 해당 비트를 끈다. 
	이를 통해 `ECHOCTL` 비트가 꺼지고, 컨트롤 문자가 화면에 표시되지 않도록 설정된다.
	따라서 `term.c_lflag &= ~ECHOCTL;`는 터미널 속성 구조체의 `c_lflag` 필드에서 `ECHOCTL` 비트를 끄는 역할을 한다.

	53줄 공부 
	`tcsetattr(STDIN_FILENO, TCSANOW, &term)`는 변경된 터미널 속성을 설정하는 함수 호출입니다.
	
	`tcsetattr` 함수는 터미널의 속성을 설정하는 함수로, 터미널 속성 구조체 `term`에 저장된 값을 터미널에 적용합니다. 이를 통해 터미널의 동작 방식, 입력 모드, 출력 모드, 제어 문자 등을 변경할 수 있습니다.
	
	인자로는 다음과 같은 값들을 전달합니다:
	- `STDIN_FILENO`: 표준 입력 파일 디스크립터(STDIN)로서, 터미널과 연결된 입력 스트림을 나타냅니다.
	- `TCSANOW`: 변경된 속성을 즉시 적용하도록 지정하는 플래그입니다. 변경된 속성은 바로 적용되어 현재의 터미널 동작에 영향을 줍니다.
	- `&term`: 변경할 터미널 속성이 저장된 구조체 변수의 주소입니다.
	
	즉, `tcsetattr(STDIN_FILENO, TCSANOW, &term)`는 `term`에 저장된 변경된 터미널 속성을 즉시 적용하여 터미널에 적용하는 역할을 합니다. 이를 통해 터미널의 동작 방식이나 입력/출력 모드가 변경될 수 있습니다.
	*/
}
