CHECKER 		=	checker

CC				=	gcc
# CFLAGS = -g -Wall -Wextra -Werror
CFLAGS 			=	-g -Wall -Wextra
MLX_FLAGS 		=	-L./ -lmlx -lX11 -lXext
INCLUDE_DIR 	=	include/
SRC_DIR 		=	src/
OBJ_DIR 		=	obj/
INCLUDES_H 		=	-I./$(INCLUDE_DIR)
DEPS =

INCLUDE_SRC 	=	mlx.h \
					visu.h \
					push_swap.h \
					get_next_line.h \

COMMON_SRC 		=	$(addprefix common_src/, \
					index.c \
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
## BECAREFUL -> TEMPORARY.C

CHECKER_SRC 	=	$(addprefix checker_src/, \
					checker.c \
					create_list_instructions.c \
					)

GNL_SRC 		=	$(addprefix gnl_src/, \
					get_next_line.c \
					get_next_line_utils.c \
					)

VISU_SRC 		=	$(addprefix visu_src/, \
					visu.c \
					render.c \
					handler.c \
					autoplay.c \
					visu_utils.c \
					render_utils.c \
					)

CHECKER_SRCS 	=	$(addprefix $(SRC_DIR), \
					${GNL_SRC} \
					${VISU_SRC} \
					${COMMON_SRC} \
					${CHECKER_SRC} \
					)

CHECKER_OBJ		=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(CHECKER_SRCS))

all: $(CHECKER)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES_H) -c -o $@ $^

$(CHECKER): $(CHECKER_OBJ) $(DEPS)
	@echo "\e[36mMaking checker...\e[0m"
	@$(CC) $(CFLAGS) $(INCLUDES_H) $(CHECKER_OBJ) $(MLX_FLAGS) -o $(CHECKER)
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
