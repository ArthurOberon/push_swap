VISU = visualizer

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra
MLX_FLAGS = -L./ -lmlx -lX11 -lXext
SRC_DIR = src/
OBJ_DIR = obj/


SRC =	main.c \
		list.c \
		utils.c \
		render.c \
		handler.c \
		render_utils.c \

VISU_SRCS = ${SRC}

VISU_OBJ = ${VISU_SRCS:.c=.o}

all: $(VISU)

$(addprefix $(OBJ_DIR), %.o) : ${SRC_DIR}%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I include/ -c -o $@ $^

$(VISU): $(addprefix $(OBJ_DIR), $(VISU_OBJ))
	@echo "\e[36mMaking visualizer...\e[0m"
	@$(CC) $(addprefix $(OBJ_DIR), $(VISU_OBJ)) $(MLX_FLAGS) -o $(VISU)
	@echo "\e[32mDone !\e[0m"


clean:
	@rm -rf $(OBJ_DIR)
	@echo "\e[31mObject files removed.\e[0m"

fclean:	clean
	@rm -f $(VISU)
	@echo "\e[31m$(VISU) removed.\e[0m"


re:		fclean all

.PHONY = all bonus clean fclean re
