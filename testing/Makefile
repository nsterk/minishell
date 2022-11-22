# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abeznik <abeznik@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/22 14:04:15 by abeznik       #+#    #+#                  #
#    Updated: 2022/11/22 14:04:17 by abeznik       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# mini srcs / dirs
INCL_DIR	:=	../includes
SRCS_DIR	:=	../srcs
OBJ_DIR		:=	../objs
MINI_OBJS	:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
VPATH		:=	$(subst $(space),:,$(shell find $(SRCS_DIR) -type d))

# unity srcs / dirs
UNITY_DIR	:=	unity
UNITY_SRC	:=	$(UNITY_DIR)/src/unity.c
UNITY_OBJ	:=	$(addprefix $(OBJ_DIR)/, $(notdir $(UNITY_SRC:.c=.o)))

# combined srcs / objs
TEST_SRCS	:=	$(wildcard *.c)
TEST_OBJS	:=	$(addprefix $(OBJ_DIR)/, $(TEST_SRCS:.c=.o))
ALL_OBJS	:=	$(TEST_OBJS) $(MINI_OBJS) $(UNITY_OBJ)

# results
RES_DIR		:=	results
RESULTS		:=	$(patsubst %.c,$(RES_DIR)/%.txt,$(TEST_SRCS))
BUILD_DIRS	:=	$(RES_DIR) $(OBJ_DIR)

# Config
FLAGS		:=	-Wall -Wextra -fsanitize=address -g
LIBS		:=	-lreadline -lhistory
EXTENSION	:=	.out

test: $(BUILD_DIRS) $(ALL_OBJS) $(RESULTS)
	@echo "success!"
	@echo results can be found in results/

$(RES_DIR)/%.txt: $(OBJ_DIR)/%$(EXTENSION)
	@$(info running $(notdir $(basename $@)))
	@-./$< > $@ 2>> $(basename $@)_errors.txt

$(OBJ_DIR)/%$(EXTENSION): $(OBJ_DIR)/%.o
	@$(CC) $(MINI_OBJS) $< $(UNITY_OBJ) $(FLAGS) $(LIBS) $(RL_LIB) -o $@

$(UNITY_OBJ): $(BUILD_DIRS)
	@$(CC) $(FLAGS) -c $(UNITY_SRC) -I$(INCL_DIR) -I$(UNITY_DIR)/src $(RL_INC) -o $@

$(OBJ_DIR)/%.o: $(notdir %.c)
	@mkdir -p $(OBJ_DIR)
	@echo compiling $(notdir $(basename $<))
	@$(CC) $(FLAGS) -c $< -I$(INCL_DIR) -I$(UNITY_DIR)/src $(RL_INC) -o $@

dtest: $(BUILD_DIRS) $(ALL_OBJS) $(RESULTS)
	lldb $(OBJ_DIR)/parse_tester$(EXTENSION)

$(RES_DIR):
	@mkdir -p $(RES_DIR)

test2: $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

echo:
	@echo

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(RES_DIR)

.PRECIOUS: $(OBJ_DIR)%$(TARGET_EXTENSION)