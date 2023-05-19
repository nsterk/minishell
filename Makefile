NAME		:=	minishell

# Colours
RED 		:=	\033[1;31m
GRN 		:=	\033[1;32m
BLUE		:=	\033[1;36m
YEL 		:=	\033[0;33m
DEF 		:=	\033[0m

USERNAME	:= $(shell whoami)

RL_LIB	:= 
ifeq ($(USERNAME), abeznik)
	RL_LIB := -L"/Users/abeznik/.brew/opt/readline/lib"
else
	RL_LIB := -L"/Users/nsterk/.brew/opt/readline/lib"
endif

RL_INC	:= 
ifeq ($(USERNAME), abeznik)
	RL_INC	:= -I/Users/abeznik/.brew/opt/readline/include
else
	RL_INC	:= -I/Users/nsterk/.brew/opt/readline/include
endif

export RL_INC
export RL_LIB

HEADERS		:= $(addprefix -I , ./includes)

OBJ_DIR		:= objs
SRC_DIR		:= srcs

SRCS		:= $(shell find srcs -iname "*.c")
OBJS		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Config
CC			:=	cc
FLAGS		:= -Wall -Wextra -g -fsanitize=address
LIBS		:=	-lreadline -lhistory

all:		$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(YEL)  Creating objects...$(DEF) %-33.33s\r" $(notdir $<)
	@$(CC) $(FLAGS) -c $< $(HEADERS) $(RL_INC) -o $@

$(NAME):	$(OBJS)
	@printf "$(YEL)\n\n  Compiling objects\n$(DEF)"
	$(CC) $(OBJS) $(LIBS) $(RL_LIB) $(FLAGS) $(HEADERS) -o $(NAME)
	@printf "$(GRN)\n  Success!$(DEF)"

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