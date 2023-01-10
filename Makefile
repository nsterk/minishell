# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arthurbeznik <arthurbeznik@student.coda      +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/07 15:02:59 by arthurbezni   #+#    #+#                  #
#    Updated: 2023/01/09 16:41:28 by arthurbezni   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:=	minishell

# Readline paths (change this to your machine)
## Codam Arthur
# export RL_LIB	:= -L/Users/abeznik/.brew/opt/readline/lib
# export RL_INC	:= -I/Users/abeznik/.brew/opt/readline/include

## Mac Arthur
export RL_LIB	:= -L/usr/local/opt/readline/lib
export RL_INC	:= -I/usr/local/opt/readline/include

# Colours
RED 		:=	\033[1;31m
GRN 		:=	\033[1;32m
BLUE		:=	\033[1;36m
YEL 		:=	\033[0;33m
DEF 		:=	\033[0m

# Directories
INCL_DIR	:=	includes
SRCS_DIR	:=	srcs
OBJ_DIR		:=	objs
VPATH 		:=	$(subst $(space),:,$(shell find srcs -type d))

# Srcs
SRCS		:=	main.c \
				prompt.c \
				lexer.c \
				parser.c \
				executor.c \
				execution.c \
				here_doc.c \
				initialisation.c \
				redirection.c \
				builtins.c \
				ms_echo.c \
				ms_pwd.c \
				ms_env.c \
				ms_exit.c \
				get_next_line.c \
				get_next_line_utils.c \
				ms_gnl.c \
				ms_gnl_utils.c \
				strjoin_free.c \
				ft_arraylen.c \
				ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_free_array.c \
				ft_itoa.c \
				ft_strlen.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_skipspace.c \
				ft_strchr.c \
				ft_isspace.c \
				ft_strlcpy.c \
				ft_strcpy.c \
				ft_substr.c \
				ft_strtrim.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_split.c \
				ft_putnbr_fd.c \
				token_new.c \
				token_append.c \
				token_insert.c \
				token_last.c \
				token_remove.c \
				token_first.c \
				token_size.c \
				ft_lstclear.c \
				test_list.c \
				init_data.c \
				init_lexer.c \
				state_type.c \
				lex_word.c \
				lex_operator.c \
				lex_space.c \
				ft_putendl_fd.c \
				ft_putstr_fd.c \
				ft_putchar_fd.c \
				ft_memcpy.c \
				exit.c \
				malloc_check.c \
				signals.c \

OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Config
CC			:=	cc
FLAGS		:= -Wall -Wextra -g -fsanitize=address
LIBS		:=	-lreadline -lhistory

all:		$(NAME)

$(NAME):	$(OBJS)
	@printf "$(YEL)\n\n  Compiling objects\n$(DEF)"
	$(CC) $(OBJS) $(FLAGS) $(LIBS) $(RL_LIB) -o $(NAME)
	@printf "$(GRN)\n  Success!$(DEF)"

$(OBJ_DIR)/%.o: $(notdir %.c)
	@mkdir -p $(OBJ_DIR)
	@printf "$(YEL)  Creating objects...$(DEF) %-33.33s\r" $(notdir $(basename $@))
	@$(CC) $(FLAGS) -c $< -I$(INCL_DIR) $(RL_INC) -o $@

db: all
	lldb $(NAME)

norm:
	norminette srcs/*

run: all
	./$(NAME)

test: all
	./$(NAME) $(ARGS)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re