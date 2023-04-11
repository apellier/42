CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Lincludes/libft -lft
NAME = libftprintf.a
SRCS = srcs/printf_utils.c \
		srcs/ft_printf.c

INCLUDE = includes/libftprintf.h

MAIN = srcs/main.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

libft:
	$(MAKE) -C ./includes/libft

$(NAME): $(OBJECTS) $(INCLUDE)
	$(MAKE) -C ./includes/libft
	cp ./includes/libft/libft.a $(NAME)
	ar -rc $@ $(OBJECTS)

clean:
	$(MAKE) clean -C ./includes/libft
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	$(MAKE) fclean -C ./includes/libft
	rm -rf $(NAME)

re: fclean all

test: all
	gcc $(CFLAGS) $(MAIN) $(NAME) 