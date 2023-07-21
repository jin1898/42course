NAME = minishell

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

LDFLAGS = -L$(shell brew --prefix readline)/lib -lreadline
INCLUDES = -I$(shell brew --prefix readline)/include/readline -I./include

LIB = -L./libft -lft -L./printf -lftprintf $(LDFLAGS)

Parsing_DIR = mandatory/Parsing/
Parsing_SRC_NAME = cmd_arr.c get_cmd_info_1.c get_cmd_info_2.c first_parsing.c second_parsing.c \
parsing_overall_structure.c trash.c parsing_command.c bundle_cmd.c \
expand_env.c replace_text.c split_space_for_path.c parsing_utill_1.c parsing_utill_2.c parsing_path.c

built_in_path = mandatory/built_in/
buint_in_src = built_in.c ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c ft_unset.c

execution_path = mandatory/execution/
execution_src = excute.c child_exit_status.c execute_single_pipe.c \
execute_multiple_pipe.c

env_path = mandatory/env/
env_src = env_converter.c env_key.c env_node_manager.c env_node.c free_exit.c env_convert_util.c

signal_path = mandatory/signal/
signal_src = signal.c signal_handler.c

redirection_path = mandatory/redirection/
redirection_src = redirection.c heredoc_util.c heredoc.c execution_redir.c

util_path = mandatory/util/
util_src = ft_perror.c ft_isnum.c ft_free.c

SRCS = mandatory/main.c \
	$(addprefix $(built_in_path), $(buint_in_src)) \
	$(addprefix $(execution_path), $(execution_src)) \
	$(addprefix $(env_path), $(env_src)) \
	$(addprefix $(signal_path), $(signal_src)) \
	$(addprefix $(util_path), $(util_src)) \
	$(addprefix $(redirection_path), $(redirection_src)) \
	$(addprefix $(Parsing_DIR), $(Parsing_SRC_NAME))

OBJ = $(SRCS:.c=.o)

SILENT = -s

all: $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft all
	make -C ./printf all
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)
	@echo "Linked into executable \033[0;32mminishell \033[0m."

%.o : %.c
	@printf "\033[Kcompile 🐹 $(notdir $<)🐱\r"
	$(CC) $(CFLAGS)  -c $^  -o $@ $(INCLUDES) -I./mandatory -I./libft -I./printf

clean :
	@make clean -C ./libft
	@make clean -C ./printf
	rm -f  $(OBJ) maker
	@echo "Linked into executable \033[0;32mminishell clean 🐹🐱\033[0m."

fclean : clean
	@make fclean -C ./libft
	@make fclean -C ./printf
	rm -f $(NAME)
	@echo "Linked into executable \033[0;32mminishell fclean 🐹🐱\033[0m."

re :
	make $(SILENT) fclean
	make $(SILENT) all
	@echo "Linked into executable \033[0;32mminishell re🐹🐱\033[0m."

.PHONY: all clean fclean re c.o

.SILENT : all clean fclean re $(OBJ) $(NAME)
