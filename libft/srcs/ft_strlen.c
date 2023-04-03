#include "../includes/libft.h"

size_t  ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    
    return (i);
}


#include <stdio.h>

int main(int argc, char **argv)
{
    printf("%ld\n", ft_strlen(argv[1]));
    return(argc);
}