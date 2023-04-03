CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
EXEC = libft
SRCS = srcs/ft_atoi.c \
	   srcs/ft_bzero.c \
	   srcs/ft_memcpy.c \
	   srcs/ft_memove.c \
	   srcs/ft_memset.c \
	   srcs/ft_strcat.c \
	   srcs/ft_strcmp.c \
	   srcs/ft_strcpy.c \
	   srcs/ft_strdup.c \
	   srcs/ft_strjoin.c \
	   srcs/ft_strlen.c \
	   srcs/ft_strncat.c \
	   srcs/ft_strncmp.c \
	   srcs/ft_strncpy.c \
	   srcs/ft_strtrim.c \
	   srcs/ft_substr.c \
	   srcs/ft_isalpha.c \
	   srcs/ft_isalnum.c \
	   srcs/ft_isdigit.c \
	   srcs/ft_isprint.c \
	   srcs/ft_tolower.c \
	   srcs/ft_toupper.c


INCLUDE = includes/libft.h

OBJECTS = $(SRCS:.c=.o)
all: $(EXEC)

$(EXEC): $(SRCS) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRCS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(EXEC)

re: fclean all