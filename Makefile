# === Project Settings ===
NAME		= so_cube_mapper
SRC_DIR		= mapper/src
OBJ_DIR		= build
INCLUDES	= -Iincludes -Iincludes/lib_ft -Iincludes/minilibx-linux
LIBFT_DIR	= includes/lib_ft
MLX_DIR		= includes/minilibx-linux

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror $(INCLUDES)
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

SRC			= $(wildcard $(SRC_DIR)/*.c)
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# === Rules ===

all: $(NAME)

$(NAME): libft mlx $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft:
	$(MAKE) -C $(LIBFT_DIR)

mlx:
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft mlx
