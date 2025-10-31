NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_printf_utils.c \
	init_format.c \
	print_char_with_format.c \
	parse_width.c \
	parse_flags.c \
	parse_precision.c \
	print_hex_with_format.c \
	print_pointer_with_format.c \
	print_string_with_format.c \
	print_unsigned_with_format.c \
	print_percent_with_format.c \
	print_integer_with_format.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@echo "Building $(NAME)..."
	@ar rcs $(NAME) $(OBJS)

bonus: all

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
