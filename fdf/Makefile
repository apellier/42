NAME = fdf

DIR = srcs/

DEPENDS = make -C includes/libft

SRC = 	$(DIR)main.c \
		$(DIR)window.c \
		$(DIR)event.c \
		$(DIR)parsing.c \
		$(DIR)transform.c \
		$(DIR)utils.c \
		$(DIR)draw.c \
		$(DIR)clear.c \
		$(DIR)color.c \
		$(DIR)parsing_checks.c \
		$(DIR)transform_utils.c \
		$(DIR)putline_utils.c \


INCLUDE =  $(DIR)fdf.h include/libft/libft.h

OBJECTS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(DEPENDS)
	gcc $(CFLAGS) -o $(NAME) $(OBJECTS) -g -Lincludes/libft -lft -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJECTS)
	$(DEPENDS) clean

fclean: clean
	rm -f $(NAME)
	$(DEPENDS) fclean

re: fclean all