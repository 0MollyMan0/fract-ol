# ----------------------------------
# PROJECT NAME
# ----------------------------------
NAME = fractol

# ----------------------------------
# COMPILATION AND FLAGS
# ----------------------------------
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -I ./

# ----------------------------------
# PATH
# ----------------------------------
SRC_DIR    = src
OBJ_DIR    = obj
LIBFT_DIR  = lib/libft
PRINTF_DIR = lib/printf
MLX_DIR    = lib/minilibx-linux

# ----------------------------------
# COLORS
# ----------------------------------
RESET       = \033[0m
BLACK       = \033[0;30m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
WHITE       = \033[0;37m

# ----------------------------------
# SOURCES
# ----------------------------------
SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/event.c \
	$(SRC_DIR)/key_pressed.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/fractal.c \
	$(SRC_DIR)/visual.c \
	$(SRC_DIR)/colors_palette.c \
	$(SRC_DIR)/verif_number.c \
	$(SRC_DIR)/colors.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ----------------------------------
# LIBRARIES
# ----------------------------------
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/printf.a
MLX   = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# ----------------------------------
# RULES
# ----------------------------------

all: $(NAME) banner

banner :
	@echo "$(BLUE) ____ $(CYAN) ____ $(MAGENTA)   __   $(RED) ___ $(YELLOW) ____ $(GREEN) _____  $(BLUE)__"
	@echo "$(BLUE)( ___)$(CYAN)(  _ \ $(MAGENTA) /__\  $(RED)/ __)$(YELLOW)(_  _)$(GREEN)(  _  )$(BLUE)(  )"
	@echo "$(BLUE))__)  $(CYAN))   / $(MAGENTA) /(__)\( $(RED)(__  $(YELLOW) )(   $(GREEN))(_)(  )$(BLUE)(__"
	@echo "$(BLUE)(__)  $(CYAN)(_)\_)$(MAGENTA)(__)(__)$(RED)\___)$(YELLOW) (__) $(GREEN)(_____)$(BLUE)(____)$(RESET)"

# Final link : libft + MLX + printf
$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	@echo "\033[1;34m[LINK] -> Creating $(NAME)...\033[0m"
	@$(CC) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLX_FLAGS) -lm -o $(NAME)
	@echo "\033[1;32m[OK] -> $(NAME) ready!\033[0m"

# Compilation of .c in .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "\033[1;33m[CC] -> $<\033[0m"
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR) -c $< -o $@

# Create obj dir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compilation of libft
$(LIBFT):
	@echo "\033[1;34m[LIBFT] -> Compiling libft...\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "\033[1;32m[OK] -> libft ready!\033[0m"

# Compilation of printf
$(PRINTF):
	@echo "\033[1;34m[PRINTF] -> Compiling printf...\033[0m"
	@$(MAKE) -C $(PRINTF_DIR) > /dev/null
	@echo "\033[1;32m[OK] -> printf ready!\033[0m"

# Clean
clean:
	@echo "\033[1;31m[CLEAN] -> Removing object files...\033[0m"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C lib/libft clean > /dev/null
	@$(MAKE) -C lib/printf clean > /dev/null

# Full Clean
fclean: clean
	@echo "\033[1;31m[FCLEAN] -> Removing executable...\033[0m"
	@rm -f $(NAME)
	@$(MAKE) -C lib/libft fclean > /dev/null
	@$(MAKE) -C lib/printf fclean > /dev/null

# Rebuild
re: fclean all

# ----------------------------------
# PHONY
# ----------------------------------
.PHONY: all clean fclean re
