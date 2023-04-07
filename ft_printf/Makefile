CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
NAME = libftprintf.a
SRCS = 

INCLUDE =

OBJECTS = $(SRCS:.c=.o)

OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	ar -rc $@ $(OBJECTS)

bonus: $(OBJECTS_BONUS) 
	ar -rc $(NAME) $(OBJECTS_BONUS)
clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all