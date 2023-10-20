CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
NAME = libftprintf.a
SRCS = srcs/printf_utils.c \
		srcs/ft_printf.c \
		srcs/print_hexa.c

INCLUDE = includes/ft_printf.h

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJECTS) $(INCLUDE)
	ar -rc $@ $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all