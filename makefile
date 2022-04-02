# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 19:11:09 by jaewpark          #+#    #+#              #
#    Updated: 2022/04/02 14:21:51 by jaewpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEB = checker

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g

SRC_DIR = ./srcs/
BNS_DIR = ./bonus/
OBJ_DIR = ./obj/
OBJB_DIR = ./objb/
INC_DIR = ./includes/

SRC_FILES = push_swap.c \
			linked.c \
			utils_a.c \
			utils_b.c \
			parsing.c \
			lis.c \
			sort_a.c \
			sort_b.c \
			sort_utils.c \
			init.c \

BNS_FILES = checker.c \
			get_next_line_util.c \
			get_next_line.c \
			operation_a.c \
			operation_b.c \
			init.c \
			linked.c \
			parsing.c \

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJB_FILES = $(BNS_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJB = $(addprefix $(OBJB_DIR), $(OBJB_FILES))
BNS = $(addprefix $(BNS_DIR), $(BNS_FILES))

ifdef WITH_BONUS
		TARGET = objb $(NAMEB)
	else
		TARGET = obj $(NAME)
endif

# all rule
all : $(TARGET)

bonus :
		make WITH_BONUS=1 all

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(INC_DIR) -o $@ -c $<

objb:
	@mkdir -p $(OBJB_DIR)
$(OBJB_DIR)%.o:$(BNS_DIR)%.c
	@gcc $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	@clear
	@echo "\033[32m║▌│█║▌│ \033[0m\033[73m█║▌│█│║▌║▌│█║▌│█║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌\033[0m\033[73m║▌│█║▌│█║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█\033[0m\033[73m║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█║▌│█│║▌║\033[0m\033[73m \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█║▌│█│║▌║ \033[0m\033[33m \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "═════════•°• $(NAME) generated •°•═════════"
	@clear
	@echo
	@echo "\033[01;31m⎹⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴\
	⎴⎴⎴⎴⎴⎴⎴⎴⎴⎸"
	@echo "\033[01;31m⎹ \033[0m\033[07;37m    Subject Name              \
	 \033[0m\033[01;31m ⎸"
	@echo "\033[01;31m⎹ \033[0m\033[01;32m    Push_swap                 \
	 \033[0m\033[01;31m ⎸"
	@echo "\033[01;31m⎹⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵\
	⎵⎵⎵⎵⎵⎵⎵⎵⎵⎸"

$(NAMEB): $(OBJB)
	@clear
	@echo "\033[32m║▌│█║▌│ \033[0m\033[73m█║▌│█│║▌║▌│█║▌│█║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌\033[0m\033[73m║▌│█║▌│█║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█\033[0m\033[73m║▌│█│║▌║ \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█║▌│█│║▌║\033[0m\033[73m \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@echo "\033[32m║▌│█║▌│ █║▌│█│║▌║▌│█║▌│█║▌│█│║▌║ \033[0m\033[33m \
	\n𝙨𝙘𝙖𝙣𝙣𝙞𝙣𝙜 𝙘𝙤𝙙𝙚..."
	@sleep 0.3
	@clear
	@$(CC) $(FLAGS) -o $(NAMEB) $(OBJB)
	@echo "═════════•°• $(NAMEB) generated •°•═════════"
	@clear
	@echo
	@echo "\033[01;31m⎹⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴⎴\
	⎴⎴⎴⎴⎴⎴⎴⎴⎴⎸"
	@echo "\033[01;31m⎹ \033[0m\033[07;37m    Make File                 \
	 \033[0m\033[01;31m ⎸"
	@echo "\033[01;31m⎹ \033[0m\033[01;32m    checker                   \
	 \033[0m\033[01;31m ⎸"
	@echo "\033[01;31m⎹⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵⎵\
	⎵⎵⎵⎵⎵⎵⎵⎵⎵⎸"
# clean rule
clean:
	@rm -Rf $(OBJ_DIR) $(OBJB_DIR)
	@echo "═════════•°• Objects removed •°•═════════"

# fclean rule
fclean: clean
	@rm -f $(NAME) $(NAMEB)
	@echo "═════════•°• $(NAME) removed •°•═════════"

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re bonus
