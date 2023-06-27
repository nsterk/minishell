
NAME			:=	minishell

# to compile this bullshit on Naomi's macbook
# export RL_LIB	:= -L/usr/local/opt/readline/lib
# export RL_INC	:= -I/usr/local/opt/readline/include

USER			:=	$(shell whoami)
export RL_LIB	:= -L/Users/$(USER)/.brew/opt/readline/lib
export RL_INC	:= -I/Users/$(USER)/.brew/opt/readline/include

# Colours
RED 			:=	\033[1;31m
GRN 			:=	\033[1;32m
BLUE			:=	\033[1;36m
YEL 			:=	\033[0;33m
DEF 			:=	\033[0m

# Directories
INCL_DIR		:=	includes
SRCS_DIR		:=	srcs
OBJ_DIR			:=	objs
VPATH 			:=	$(subst $(space),:,$(shell find srcs -type d))

# "Main" srcs
SRCS			:=	main.c \
					lexer.c \
					parser.c \
					expander.c \
					executor.c \
					builtins.c \
					signals.c \
					#prompt.c \

# Parser srcs
SRCS_PARSER		:=	parse_args.c \
					parse_pipe.c \
					syntax_rules.c \
					cmd_utils.c \
					red_utils.c \

# Lexer srcs
SRCS_LEXER		:=	delimit_token.c \
					lex_operator.c \
					lex_space.c \
					lex_word.c \
					lex_quote.c \
					state_type.c \
					token_add.c \
					token_find.c \
					token_free.c \
					token_remove.c \

# Expander srcs
SRCS_EXPANDER	:=	expand_utils.c \
					word_splitting.c \

# Signals srcs
SRCS_SIGNALS	:=	init_signals.c \

# Executor srcs
SRCS_EXEC		:=	execution.c \
					here_doc.c \
					initialisation.c \
					redirection.c \

# Builtins srcs
SRCS_BUILTINS	:=	builtins_utils.c \
					cd_utils.c \
					export_utils.c \
					ms_cd.c \
					ms_echo.c \
					ms_env.c \
					ms_exit.c \
					ms_export.c \
					ms_pwd.c \
					ms_unset.c \
# Utils srcs
SRCS_UTILS		:=	exits.c \
					gnl.c \
					gnl_utils.c \
					init_data.c \
					init_envp.c \
					reinit_data.c \
					init_parser.c \
					ft_array_len.c \
					ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_free_array.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isspace.c \
					ft_itoa.c \
					ft_memcpy.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_replace.c \
					ft_skipspace.c \
					ft_split.c \
					ft_strcheck.c \
					ft_strchr.c \
					ft_strcpy.c \
					ft_strdup.c \
					ft_strjoin.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strncmp.c \
					ft_strndup.c \
					ft_substr.c \
					malloc_check.c \
					strjoin_free.c \
					test_list.c \
					test_parser.c \

# Objects
OBJS			:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_P			:=	$(addprefix $(OBJ_DIR)/, $(SRCS_PARSER:.c=.o))
OBJS_L			:=	$(addprefix $(OBJ_DIR)/, $(SRCS_LEXER:.c=.o))
OBJS_X			:=	$(addprefix $(OBJ_DIR)/, $(SRCS_EXPANDER:.c=.o))
OBJS_S			:=	$(addprefix $(OBJ_DIR)/, $(SRCS_SIGNALS:.c=.o))
OBJS_E			:=	$(addprefix $(OBJ_DIR)/, $(SRCS_EXEC:.c=.o))
OBJS_B			:=	$(addprefix $(OBJ_DIR)/, $(SRCS_BUILTINS:.c=.o))
OBJS_U			:=	$(addprefix $(OBJ_DIR)/, $(SRCS_UTILS:.c=.o))

# Config
CC				:=	cc
ifdef debug
	FLAGS		:=	-g -fsanitize=address
else ifdef dev
	FLAGS		:=	-Wall -Wextra -g -fsanitize=address
else
	FLAGS		:=	-Wall -Wextra -Werror
endif
LIBS			:=	-lreadline -lhistory

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJS_P) $(OBJS_L) $(OBJS_X) $(OBJS_S) $(OBJS_E) $(OBJS_B) $(OBJS_U)
	@printf "$(YEL)\n\n  Compiling objects\n$(DEF)"
	$(CC) $(OBJS) $(OBJS_P) $(OBJS_L) $(OBJS_X) $(OBJS_S) $(OBJS_E) $(OBJS_B) $(OBJS_U) $(FLAGS) $(LIBS) $(RL_LIB) -o $(NAME)
	@printf "$(GRN)\n  Success!$(DEF)"

# $(NAME):	$(OBJS) $(OBJS_P) $(OBJS_L) $(OBJS_X) $(OBJS_S) $(OBJS_E) $(OBJS_B) $(OBJS_U)
# 	@printf "$(YEL)\n\n  Compiling objects\n$(DEF)"
# 	$(CC) $(OBJS) $(OBJS_P) $(OBJS_L) $(OBJS_X) $(OBJS_S) $(OBJS_E) $(OBJS_B) $(OBJS_U) $(FLAGS) $(LIBS) -lhistory -lreadline -o $(NAME)
# 	@printf "$(GRN)\n  Success!$(DEF)"

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