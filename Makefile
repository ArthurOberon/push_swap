PUSH_SWAP = push_swap
CHECKER = checker

CC = cc
CFLAGS = -g
SRC_DIR = src/
OBJ_DIR = obj/


COMMON_SRC = 	move.c \
				utils.c \
				parse.c \
				merge_str.c \
				operations.c \
				list_piles.c \
				print_functions.c \
				list_instructions.c \
				\
				temporary.c \

## BECAREFUL -> TEMPORARY.C

PS_SRC =	index.c \
			push_swap.c \
			list_order.c \
			piles_utils.c \
			calcul_move.c \

#preset_move_functions.c \

CHECKER_SRC =	checker.c \
				list_create_instructions.c \

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
