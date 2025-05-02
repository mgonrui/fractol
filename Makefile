# Project Name
NAME		= fractol

# Compiler & Flags
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O3

# Directories
MLX_DIR		= mlx_linux
LIBFT_DIR	= libft

# Source Files
CFILES		= main.c \
			  render.c \
			  equation.c \
			  events.c \
			  utils.c \
			  handle_inputs.c
OFILES		= $(CFILES:.c=.o)

# Includes
INCLUDES	= -I$(MLX_DIR) -I$(LIBFT_DIR) -I/usr/include

# Libraries
MLX_LIB		= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
LIBFT_LIB	= -L$(LIBFT_DIR) -lft

# Rules
all: mlx libft $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

mlx:
	@make -C $(MLX_DIR)

libft:
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OFILES)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all mlx libft clean fclean re help
