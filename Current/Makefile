PUSH_SWAP = push_swap
CHECKER = checker

CC = gcc
# CFLAGS = -g -Wall -Wextra -Werror
CFLAGS = -g -Wall -Wextra
INCLUDES_DIR = include/
SRC_DIR = src/
OBJ_DIR = obj/
INCLUDES_H = -I./$(INCLUDES_DIR)
DEPS =
# DEPS = $(INCLUDES_DIR)push_swap.h Makefile

COMMON_SRC = 	$(addprefix common_src/, \
				utils.c \
				parse.c \
				merge_str.c \
				operations.c \
				piles_utils.c \
				print_functions.c \
				list_instructions_utils.c \
				\
				temporary.c \
				)
# BECAREFUL -> TEMPORARY.C

ALGO_SRC =		$(addprefix algo_src/, \
				algo.c \
				algo_utils.c \
				do_best_move_utils.c \
				do_best_move_utils_2.c \
				)

MOVE_SRC =		$(addprefix move_src/, \
				move.c \
				preset_move.c \
				preset_move_utils.c \
				optimize_rotation.c \
				)

PILES_SRC =		$(addprefix piles_src/, \
				piles.c \
				piles_min_max.c \
				piles_ascending_utils.c \
				piles_ascending_multiples.c \
				piles_multiples_ascending.c \
				piles_multiples_descending.c \
				)

PS_SRC =		$(addprefix push_swap_src/, \
				index.c \
				push_swap.c \
				$(ALGO_SRC) \
				$(MOVE_SRC)	\
				$(PILES_SRC) \
				)


CHECKER_SRC =	$(addprefix checker_src/, \
				checker.c \
				create_list_instructions.c \
				)

GNL_SRC =		$(addprefix gnl_src/, \
				get_next_line.c \
				get_next_line_utils.c \
				)

PS_SRCS =	$(addprefix $(SRC_DIR), \
			$(COMMON_SRC) \
			$(PS_SRC) \
			)

CHECKER_SRCS = $(addprefix $(SRC_DIR), \
				${COMMON_SRC} \
				${CHECKER_SRC} \
				${GNL_SRC} \
				)

PS_OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(PS_SRCS))
CHECKER_OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(CHECKER_SRCS))

all: $(PUSH_SWAP)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES_H) -c -o $@ $^

$(PUSH_SWAP): $(PS_OBJ) $(DEPS)
	@echo "\e[36mMaking push_swap...\e[0m"
	@$(CC) $(INCLUDES_H) $(PS_OBJ) -o $(PUSH_SWAP)
	@echo "\e[32mDone !\e[0m"

$(CHECKER): $(CHECKER_OBJ) $(DEPS)
	@echo "\e[36mMaking checker...\e[0m"
	@$(CC) $(INCLUDES_H) $(CHECKER_OBJ) -o $(CHECKER)
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
