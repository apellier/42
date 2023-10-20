CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
NAME = libft.a
DEPENDS = make -C ./ft_printf
SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c \
	   ft_secure_free.c \

SRCS_BONUS = ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstadd_back.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c \
			 ft_lstmap.c

INCLUDE = libft.h ft_printf/includes/ft_printf.h get_next_line/get_next_line.h

OBJECTS = $(SRCS:.c=.o)

OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	$(DEPENDS)
	ar -rc $@ $(OBJECTS) ft_printf/srcs/*.o

bonus: $(OBJECTS_BONUS) 
	ar -rc $(NAME) $(OBJECTS_BONUS)
clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)
	$(DEPENDS) clean

fclean: clean
	rm -rf $(NAME)
	$(DEPENDS) fclean

re: fclean all