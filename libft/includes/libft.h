#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>


typedef struct	s_list
{
	void			*content;
	size_t		content_size;
	struct s_list	*next;
}				t_list;

size_t  ft_strlen(const char *s);
# define INT_MAX +2147483647
/*
memset 0
bzero 0
memcpy 0
memmove 0
isalpha 0
isdigit 0
isalnum 0
isascii 0
isprint 0
strlen 0
strlcpy
strlcat
touuper 0
tolower 0
strrchr
strncmp
memchr
memcmp
strnstr
atoi 0
calloc
strdup 0
*/

char *ft_substr(char const *s, unsigned int start, size_t len);

char *ft_strjoin(char const *s1, char const *s2);

char *ft_strtrim(char const *s1, char const *set);
/*
Parameters #1. The string to be trimmed.
#2. The reference set of characters to trim.

Return value The trimmed string. NULL if the allocation fails.

Description Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/

// bonus
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdeleone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));



#endif