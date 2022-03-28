NAME = push_swap

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/

SRC_FILES = push_swap.c \
			linked_new.c \
			linked.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# all rule
all: obj  $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(INC_DIR) -o $@ -c $<

# Compiling
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

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@echo "═════════•°• Objects removed •°•═════════"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "═════════•°• $(NAME) removed •°•═════════"

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re
