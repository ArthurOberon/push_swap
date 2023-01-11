PUSH_SWAP = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
OBJ_DIR = obj/

PS_SRC =	ft_split.c \
			push_swap.c \
			list_functions.c \
			print_functions.c \
			useful_functions.c \
			list_functions_2.c \
			operations_functions.c \
			temporary_functions.c \

## BECAREFUL -> TEMPORARY_FUNCITONS.C

CHECKER_SRC =	checker.c \
				ft_split.c \
				list_functions.c \
				print_functions.c \
				useful_functions.c \
				list_functions_2.c \
				operations_functions.c \
				temporary_functions.c \

PS_OBJ = ${PS_SRC:.c=.o}
CHECKER_OBJ = ${CHECKER_SRC:.c=.o}

$(addprefix $(OBJ_DIR), %.o) : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I include/ -c -o $@ $^

$(CHECKER): $(addprefix $(OBJ_DIR), $(CHECKER_OBJ))
	@echo "Making checker..."
	@$(CC) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) -I include/ -o $(CHECKER)
	@echo "Done !"

$(PUSH_SWAP): $(addprefix $(OBJ_DIR), $(PS_OBJ))
	@echo "Making push_swap..."
	@$(CC) $(addprefix $(OBJ_DIR), $(PS_OBJ)) -I include/ -o $(PUSH_SWAP)
	@echo "Done !"

all: $(PUSH_SWAP) $(CHECKER)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files removed."

fclean:	clean
	@rm -f $(PUSH_SWAP)
	@echo "$(PUSH_SWAP) removed."
	@rm -f $(CHECKER)
	@echo "$(CHECKER) removed."

re:		fclean all

.PHONY = all clean fclean re
