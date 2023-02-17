CHECKER = checker

CC = gcc
# CFLAGS = -g -Wall -Wextra -Werror
INCLUDE = include/
CFLAGS = -g -Wall -Wextra
MLX_FLAGS = -L./ -lmlx -lX11 -lXext
SRC_DIR = src/
OBJ_DIR = obj/


INCLUDE_SRC =	mlx.h \
				visu.h \
				push_swap.h \
				get_next_line.h \


COMMON_SRC = 	utils.c \
				index.c \
				parse.c \
				merge_str.c \
				operations.c \
				piles_utils.c \
				print_functions.c \
				list_instructions_utils.c \
				\
				temporary.c \

## BECAREFUL -> TEMPORARY.C

CHECKER_SRC =	checker.c \
				create_list_instructions.c \

GNL_SRC =		get_next_line.c \
				get_next_line_utils.c \

VISU_SRC =		visu.c \
				render.c \
				handler.c \
				autoplay.c \
				visu_utils.c \
				render_utils.c \

# list.c

INCLUDE_SRCS = $(addprefix($(INCLUDE_SRC), $(INCLUDE)))

CHECKER_SRCS = ${COMMON_SRC} ${CHECKER_SRC} ${GNL_SRC} ${VISU_SRC}

CHECKER_OBJ = ${CHECKER_SRCS:.c=.o}
OBJ = ${SRCS:.c=.o}


all: $(CHECKER)

$(addprefix $(OBJ_DIR), %.o): $(SRC_DIR)%.c $(INCLUDE_SRCS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c -o $@ $^

$(CHECKER): $(addprefix $(OBJ_DIR), $(CHECKER_OBJ))
	@echo "\e[36mMaking checker...\e[0m"
	@$(CC) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) $(MLX_FLAGS) -o $(CHECKER)
	@echo "\e[32mDone !\e[0m"

bonus: $(CHECKER)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\e[31mObject files removed.\e[0m"

fclean:	clean
	@rm -f $(CHECKER)
	@echo "\e[31m$(CHECKER) removed.\e[0m"

re:		fclean all

.PHONY = all bonus clean fclean re
