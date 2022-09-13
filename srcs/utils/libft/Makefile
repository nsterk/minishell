# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nsterk <nsterk@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 11:29:07 by nsterk        #+#    #+#                  #
#    Updated: 2021/07/09 10:54:49 by nsterk        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
HEADER		=	libft.h
REG_FILES 	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
				ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c \
				ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strjoin.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
				ft_strnlen.c ft_strnstr.c ft_strmapi.c ft_strrchr.c \
				ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
				ft_strclen.c ft_strcdup.c ft_strccpy.c ft_skipspace.c \
				ft_free_array.c
BONUS_FILES =	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
				ft_lstnew.c ft_lstsize.c
REG_OBJS	=	$(REG_FILES:%.c=%.o)
BONUS_OBJS	=	$(BONUS_FILES:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -g
OPTIONS		=	ar rcs
RM			=	rm -f

ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJS) ${BONUS_OBJS}
else
OBJ_FILES = $(REG_OBJS)
endif

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
		$(OPTIONS) $(NAME) $(OBJ_FILES)

%.o: %.c	$(HEADER)
	@printf "Creating Libft objects... %-33.33s\r" $@
	@$(CC) -c $(CFLAGS) -o $@ $<

bonus:
	@ $(MAKE) WITH_BONUS=1 all

clean:
	@ $(RM) $(REG_OBJS) ${BONUS_OBJS}

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus %.o
