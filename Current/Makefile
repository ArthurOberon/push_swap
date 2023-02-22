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

# SOURCES USE BY PUSH_SWAP AND CHEKER
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

# SOURCES USE FOR THE SECOND ALGO TO DO THE FASTEST MOVE (MOVE WITH THE LESS OPERATIONS) (USED BY PUSH_SWAP)
ALGO_SRC =		$(addprefix algo_src/, \
				algo.c \
				algo_utils.c \
				piles_min_max.c \
				do_best_move_utils.c \
				do_best_move_utils_2.c \
				)

# SOURCES USE TO DO THE OPERATION (SA, RA, PA, ...) ON THE PILES (USED BY PUSH_SWAP)
MOVE_SRC =		$(addprefix move_src/, \
				move.c \
				preset_move.c \
				preset_move_utils.c \
				optimize_rotation.c \
				)

# SOURCES UTILS FOR PUSH_SWAP (USED BY PUSH_SWAP)
PS_UTILS_SRC =	$(addprefix push_swap_utils_src/, \
				index.c \
				push_swap_utils.c \
				)

# SOURCES USE FOR LIS (Longest Increase Subsequence) (USED BY PUSH_SWAP)
LIS_SRC =		$(addprefix lis_src/, \
				lis.c \
				\
				piles_order_multiples_utils.c \
				piles_order_multiples.c \
				piles_multiples_ascending.c \
				piles_multiples_descending.c \
				)

# SOURCES ONLY FOR PUSH_SWAP
PS_SRC =		$(addprefix push_swap_src/, \
				push_swap.c \
				$(LIS_SRC) \
				$(ALGO_SRC) \
				$(MOVE_SRC)	\
				$(PS_UTILS_SRC) \
				)

# SOURCES USE FOR GET_NEXT_LINE (USED BY CHECKER)
GNL_SRC =		$(addprefix gnl_src/, \
				get_next_line.c \
				get_next_line_utils.c \
				)

# SOURCES FOR ONLY CHECKER
CHECKER_SRC =	$(addprefix checker_src/, \
				checker.c \
				create_list_instructions.c \
				$(GNL_SRC) \
				)

# ALL SOURCES FOR PUSH_SWAP
PS_SRCS =	$(addprefix $(SRC_DIR), \
			$(COMMON_SRC) \
			$(PS_SRC) \
			)

# ALL SOURCES FOR CHECKER
CHECKER_SRCS = $(addprefix $(SRC_DIR), \
				${COMMON_SRC} \
				${CHECKER_SRC} \
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
