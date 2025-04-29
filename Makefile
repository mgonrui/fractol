NAME=bin
CFILES= main.c \
		render.c \
		algorythm.c \
		events.c \
		utils.c \
		handle_inputs.c
CC=gcc
OFILES=$(CFILES:.c=.o)

%.o : %.c fractol.h
	$(CC) -Wall -Wextra -I/usr/include -Imlx_linux -O3 -c $< -o $@


all: $(NAME)
$(NAME): $(OFILES)
	$(CC) $(OFILES) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -o $(NAME)

clean:
	@ rm -f $(OFILES)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
