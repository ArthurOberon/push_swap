PUSH_SWAP = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
OBJ_DIR = obj/

PS_SRC =	push_swap.c \
			list_functions.c \
			print_functions.c \
			parse_functions.c \
			useful_functions.c \
			operations_functions.c \
			\
			temporary_functions.c \

## BECAREFUL -> TEMPORARY_FUNCITONS.C

CHECKER_SRC =	checker.c \
				list_functions.c \
				parse_functions.c \
				print_functions.c \
				useful_functions.c \
				operations_functions.c \
				\
				temporary_functions.c \

PS_OBJ = ${PS_SRC:.c=.o}
CHECKER_OBJ = ${CHECKER_SRC:.c=.o}

$(addprefix $(OBJ_DIR), %.o) : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I include/ -c -o $@ $^

$(CHECKER): $(addprefix $(OBJ_DIR), $(CHECKER_OBJ))
	@echo "\e[36mMaking checker...\e[0m"
	@$(CC) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) -I include/ -o $(CHECKER)
	@echo "\e[32mDone !\e[0m"

$(PUSH_SWAP): $(addprefix $(OBJ_DIR), $(PS_OBJ))
	@echo "\e[36mMaking push_swap...\e[0m"
	@$(CC) $(addprefix $(OBJ_DIR), $(PS_OBJ)) -I include/ -o $(PUSH_SWAP)
	@echo "\e[32mDone !\e[0m"

all: $(PUSH_SWAP) $(CHECKER)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\e[31mObject files removed.\e[0m"

fclean:	clean
	@rm -f $(PUSH_SWAP)
	@echo "\e[31m$(PUSH_SWAP) removed.\e[0m"
	@rm -f $(CHECKER)
	@echo "\e[31m$(CHECKER) removed.\e[0m"

re:		fclean all

.PHONY = all clean fclean re
