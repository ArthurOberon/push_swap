PUSH_SWAP = push_swap
CHECKER = checker

CC = gcc
# CFLAGS = -g -Wall -Wextra -Werror
CFLAGS = -g -Wall -Wextra
SRC_DIR = src/
OBJ_DIR = obj/


COMMON_SRC = 	utils.c \
				parse.c \
				merge_str.c \
				operations.c \
				piles_utils.c \
				print_functions.c \
				list_instructions_utils.c \
				\
				temporary.c \

## BECAREFUL -> TEMPORARY.C

PS_SRC =	algo.c \
			move.c \
			index.c \
			piles.c \
			push_swap.c \
			algo_utils.c \
			preset_move.c \
			piles_min_max.c \
			piles_ascending.c \
			preset_move_utils.c \
			optimize_rotation.c \
			do_best_move_utils.c \
			do_best_move_utils_2.c \
			piles_ascending_utils.c \

CHECKER_SRC =	checker.c \
				create_list_instructions.c \

GNL_SRC =		get_next_line.c \
				get_next_line_utils.c \

PS_SRCS = ${COMMON_SRC} ${PS_SRC}
CHECKER_SRCS = ${COMMON_SRC} ${CHECKER_SRC} ${GNL_SRC}

PS_OBJ = ${PS_SRCS:.c=.o}
CHECKER_OBJ = ${CHECKER_SRCS:.c=.o}
OBJ = ${SRCS:.c=.o}



all: $(PUSH_SWAP)

$(addprefix $(OBJ_DIR), %.o): $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I include/ -c -o $@ $^

$(PUSH_SWAP): $(addprefix $(OBJ_DIR), $(PS_OBJ))
	@echo "\e[36mMaking push_swap...\e[0m"
	@$(CC) $(addprefix $(OBJ_DIR), $(PS_OBJ)) -I include/ -o $(PUSH_SWAP)
	@echo "\e[32mDone !\e[0m"

$(CHECKER): $(addprefix $(OBJ_DIR), $(CHECKER_OBJ))
	@echo "\e[36mMaking checker...\e[0m"
	@$(CC) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) -I include/ -o $(CHECKER)
	@echo "\e[32mDone !\e[0m"

bonus: $(CHECKER)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\e[31mObject files removed.\e[0m"

fclean:	clean
	@rm -f $(PUSH_SWAP)
	@echo "\e[31m$(PUSH_SWAP) removed.\e[0m"
	@rm -f $(CHECKER)
	@echo "\e[31m$(CHECKER) removed.\e[0m"

re:		fclean all

.PHONY = all bonus clean fclean re
