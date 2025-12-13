# ----------------------------------
# NOM DU PROJET
# ----------------------------------
NAME = fractol

# ----------------------------------
# COMPILATEUR ET FLAGS
# ----------------------------------
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -I ./

# ----------------------------------
# CHEMINS
# ----------------------------------
SRC_DIR    = src
OBJ_DIR    = obj
LIBFT_DIR  = lib/libft
PRINTF_DIR = lib/printf
MLX_DIR    = lib/minilibx-linux

# ----------------------------------
# LISTE DES SOURCES (À REMPLACER PAR TOUS TES .c)
# ----------------------------------
SRC = $(SRC_DIR)/main.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ----------------------------------
# LIBRAIRIES
# ----------------------------------
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/printf.a
MLX   = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# ----------------------------------
# RÈGLES
# ----------------------------------

all: $(NAME)

# Link final : libft + MLX + printf
$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	@echo "\033[1;34m[LINK] -> Creating $(NAME)...\033[0m"
	@$(CC) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[1;32m[OK] -> $(NAME) ready!\033[0m"

# Compilation des .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "\033[1;33m[CC] -> $<\033[0m"
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR) -c $< -o $@

# Création du dossier obj si nécessaire
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compilation de libft
$(LIBFT):
	@echo "\033[1;34m[LIBFT] -> Compiling libft...\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "\033[1;32m[OK] -> libft ready!\033[0m"

# Compilation de printf
$(PRINTF):
	@echo "\033[1;34m[PRINTF] -> Compiling printf...\033[0m"
	@$(MAKE) -C $(PRINTF_DIR) > /dev/null
	@echo "\033[1;32m[OK] -> printf ready!\033[0m"

# Nettoyage des .o
clean:
	@echo "\033[1;31m[CLEAN] -> Removing object files...\033[0m"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C lib/libft clean > /dev/null
	@$(MAKE) -C lib/printf clean > /dev/null

# Nettoyage complet
fclean: clean
	@echo "\033[1;31m[FCLEAN] -> Removing executable...\033[0m"
	@rm -f $(NAME)
	@$(MAKE) -C lib/libft fclean > /dev/null
	@$(MAKE) -C lib/printf fclean > /dev/null

# Rebuild complet
re: fclean all

# ----------------------------------
# PHONY
# ----------------------------------
.PHONY: all clean fclean re
