NAME = libftprintf.a

SRCS = srcs/parser/normalized_format.c \
	srcs/parser/parse_flags.c \
	srcs/parser/parse_precision.c \
	srcs/parser/parse_width.c \
	srcs/print/print_char_with_format.c \
	srcs/print/print_hex_with_format.c \
	srcs/print/print_int_with_format.c \
	srcs/print/print_pointer_with_format.c \
	srcs/print/print_string_with_format.c \
	srcs/print/print_unsigned_with_format.c \
	srcs/print/print_percent_with_format.c \
	srcs/utils/format_number.c \
	srcs/utils/format_string.c \
	srcs/utils/utils.c \
	srcs/utils/utils2.c \
	srcs/utils/format_utils/apply_hash.c \
	srcs/utils/format_utils/apply_padding.c \
	srcs/utils/format_utils/apply_precision_string.c \
	srcs/utils/format_utils/apply_precision.c \
	srcs/utils/format_utils/apply_sign.c \
	ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Building $(NAME)..."
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "✅ $(NAME) built successfully!"

$(LIBFT):
	@make -C $(LIBFT_DIR)

bonus: all

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
