# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arthurbeznik <arthurbeznik@student.coda      +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/07 15:02:59 by arthurbezni   #+#    #+#                  #
#    Updated: 2022/09/13 16:06:23 by arthurbezni   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:=	minishell

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
SRCS		=	main.c \

OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Config
CC			:=	cc
FLAGS		:= -Wall -Wextra -g #-Werror
ARGS		:=	2 800 200 200

all:		$(NAME)
	
$(NAME):	$(OBJS)
	@echo "$(YEL)\n  Compiling srcs$(DEF)"
	$(CC) $(OBJS) $(FLAGS) -lreadline -o $(NAME)
	@echo "$(GRN)\n  Success!$(DEF)"

$(OBJ_DIR)/%.o: $(notdir %.c)
	@mkdir -p $(OBJ_DIR)
	@echo "compiling $(notdir $(basename $@))"
	@$(CC) $(FLAGS) -c $< -I$(INCL_DIR) -o $@


## Add GNL, libft Makefiles


db: all
	lldb $(NAME) -- $(ARGS)

norm:
	norminette srcs/*

test: all
	./$(NAME) $(ARGS)

clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re