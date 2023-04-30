/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:59:49 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/30 16:55:16 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_db	db;
	int		i;

	what_parameter(argv, argc, &db);
	i = find_path(envp, &db);
	if (!i)
		return (0);
	for (int i = 0; db.path[i] != 0; i++)
		printf("db.path[%d] [%s]\n",i,db.path[i]);
	//경로 저장완료, infile outfile 다 연결함.
	make_and_open_pipe(argc, &db);
	make_child(&db, argv, envp);
	close_and_wait(&db);
	free_everything(&db);
}

void	what_parameter(char **argv, int argc, t_db *db)
{
	if (argv[1] == NULL || argc == 1)
		error_message("Invalid number of arguments. \n");
	if (ft_strcmp(argv[1], "here_doc") == 0 && argv[1] != 0)
	{
		db->h_flag = 1;
		if (argc < 6)
			error_message("Invalid number of arguments. \n");
		here_doc(argv[2], db);
		db->outfilenum = open(argv[argc - 1], O_WRONLY \
		| O_CREAT | O_APPEND, 0644);
	}
	else
	{
		db->h_flag = 0;
		if (argc < 5)
			error_message("Invalid number of arguments. \n");
		db->infilenum = open(argv[1], O_RDONLY | O_CREAT, 0644);
		db->outfilenum = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	if (db->outfilenum < 0 || db->infilenum < 0)
		error_message("Can't open file. \n");
}

void	error_message(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (*s1_c == *s2_c)
	{
		if (*s1_c == '\0')
			return (0);
		s1_c++;
		s2_c++;
	}
	return (*s1_c - *s2_c);
}

void	here_doc(char *eof, t_db *db)
{
	int		tmp_heredoc;
	char	*getbox;

	tmp_heredoc = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_heredoc < 0)
		error_message("heredoc error\n");
	while (1)
	{
		getbox = NULL;
		write(1, "here_doc> ", ft_strlen("here_doc> "));
		while (getbox == NULL)
			getbox = get_next_line(STDIN_FILENO);
		if ((ft_strcmp2(getbox, eof, ft_strlen(eof))) == 0)
			break ;
		write(tmp_heredoc, getbox, ft_strlen(getbox));
		free(getbox);
	}
	free(getbox);
	close(tmp_heredoc);
	db->infilenum = open(".heredoc_tmp", O_RDONLY);
	if (db->infilenum < 0)
	{
		unlink(".heredoc_tmp");
		error_message("here_doc error");
	}
	printf("sucess!!!!!!!!!!!!!!!!!!!!\n");
}
