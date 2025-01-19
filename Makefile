CFLAGS		= -Wall -Wextra -Werror -I.
SRC_DIR		= src
BONUS_DIR	= src_bonus
GNL_DIR		= get_next_line
MLX_DIR		= minilibx-linux
TEX_DIR		= textures
MAP_DIR		= maps

SRC_FILES = $(SRC_DIR)/main.c \
			$(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c \
			$(SRC_DIR)/check_map.c\
			$(SRC_DIR)/check_paths.c\
			$(SRC_DIR)/check_pos.c\
			$(SRC_DIR)/draw.c\
			$(SRC_DIR)/error.c\
			$(SRC_DIR)/find_in_map.c\
			$(SRC_DIR)/import_data.c\
			$(SRC_DIR)/import_dfs.c\
			$(SRC_DIR)/keys.c\
			$(SRC_DIR)/pathfinder.c\
			$(SRC_DIR)/sprite.c\
			$(SRC_DIR)/utils.c\


# BONUS_FILES = $(BONUS_DIR)/main_bonus.c \
# 			$(GNL_DIR)/get_next_line.c \
# 			$(GNL_DIR)/get_next_line_utils.c \
# 			$(BONUS_DIR)/check_map_bonus.c\
# 			$(BONUS_DIR)/check_paths_bonus.c\
# 			$(BONUS_DIR)/check_pos_bonus.c\
# 			$(BONUS_DIR)/draw_bonus.c\
# 			$(BONUS_DIR)/error_bonus.c\
# 			$(BONUS_DIR)/find_in_map_bonus.c\
# 			$(BONUS_DIR)/import_data_bonus.c\
# 			$(BONUS_DIR)/import_dfs_bonus.c\
# 			$(BONUS_DIR)/keys_bonus.c\
# 			$(BONUS_DIR)/pathfinder_bonus.c\
# 			$(BONUS_DIR)/sprite_bonus.c\
# 			$(BONUS_DIR)/utils_bonus.c\

BONUS_FILES = $(BONUS_DIR)/main.c\
			$(GNL_DIR)/get_next_line.c\
			$(GNL_DIR)/get_next_line_utils.c\
			$(BONUS_DIR)/check_map.c\
			$(BONUS_DIR)/check_paths.c\
			$(BONUS_DIR)/check_pos.c\
			$(BONUS_DIR)/draw.c\
			$(BONUS_DIR)/error.c\
			$(BONUS_DIR)/find_in_map.c\
			$(BONUS_DIR)/import_data.c\
			$(BONUS_DIR)/import_dfs.c\
			$(BONUS_DIR)/keys.c\
			$(BONUS_DIR)/pathfinder.c\
			$(BONUS_DIR)/sprite.c\
			$(BONUS_DIR)/utils.c\

OBJ_FILES = $(SRC_FILES:.c=.o)

BONUS_OBJ_FILES = $(BONUS_FILES:.c=.o)

NAME = so_long

BONUS_NAME = so_long_bonus

MLX_LIB = $(MLX_DIR)/libmlx.a
all: $(NAME)

$(NAME): $(OBJ_FILES) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(MLX_DIR) -L. -lmlx -lX11 -lXext  -o $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ_FILES) $(MLX_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJ_FILES) -L$(MLX_DIR) -L. -lmlx -lX11 -lXext  -o $(BONUS_NAME)

clean:
	rm -f $(OBJ_FILES)
	rm -f $(BONUS_OBJ_FILES)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus