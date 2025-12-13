NAME        = printf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I ./
AR          = ar rcs

SRC = ft_printf.c ft_putchar.c ft_putnbr_hex.c ft_putnbr.c ft_putp.c \
      ft_putnbr_u.c ft_putstr.c ft_type.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
