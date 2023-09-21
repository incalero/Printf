NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC_FILES = ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_printf.c \
			ft_putnbr_unsigned.c \
			str_direccion.c \
			put_hexa_x.c \
			put_hexa_X.c \
			ft_selected.c \

HEADER = printf.h
LIBC = ar rcs

OBJS = $(SRC_FILES:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAG) $^

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re