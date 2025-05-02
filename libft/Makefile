CFILES =ft_isdigit.c\
						ft_isalnum.c\
						ft_isalpha.c\
						ft_isascii.c\
						ft_isprint.c\
						ft_strlen.c\
						ft_memset.c\
						ft_bzero.c\
						ft_memcpy.c\
						ft_memmove.c\
						ft_strlcpy.c\
						ft_strlcat.c\
						ft_toupper.c\
						ft_tolower.c\
						ft_strchr.c\
						ft_strncmp.c\
						ft_memchr.c\
						ft_memcmp.c\
						ft_strnstr.c\
						ft_atoi.c\
						ft_calloc.c\
						ft_strdup.c\
						ft_substr.c\
						ft_strjoin.c\
						ft_strtrim.c\
						ft_putchar_fd.c\
						ft_putstr_fd.c\
						ft_putendl_fd.c\
						ft_putnbr_fd.c\
						ft_itoa.c\
						ft_strrchr.c\
						ft_strmapi.c\
						ft_striteri.c\
						ft_split.c

NAME = libft.a
CC = gcc 
CFLAGS = -Wall -Werror -Wextra
OBJECTS = $(CFILES:.c=.o) 

# create library
$(NAME) : $(OBJECTS)
	@ ar crs $(NAME) $(OBJECTS) 

# create objects
OBJECTS : CFILES
	@ $(CC) $(CFLAGS) -c -o $@ $< 

# build library
all: $(NAME)

# clean objects
clean:
	@ rm -rf $(OBJECTS)

# clean objects and library
fclean: clean
	@ rm -f $(NAME)

# clean objects and library and build all 
re: fclean all 

.PHONY: all clean fclean re