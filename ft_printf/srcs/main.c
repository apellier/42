#include "../includes/libftprintf.h"

#include <stdio.h>

int	main(void)
{
	int a = -42;
	char c = 'c';
	char *s = "salut";
	int d = 43;
	printf("Ceci est un nombre : %d, c'est aussi un nombre %i.\nLe meme nombre en hexadecimal %x et en majuscule %X\n Voici un unsigned ! %u et encore un petit %%\n.Passons aux phrases maintenant, voici un charactere %c et une phrase %s\nVoici un pointeur en hexa %p\n\n", a, a, a, a, d, c, s, s);
	ft_printf("Ceci est un nombre : %d, c'est aussi un nombre %i.\nLe meme nombre en hexadecimal %x et en majuscule %X\n Voici un unsigned ! %u et encore un petit %%\n.Passons aux phrases maintenant, voici un charactere %c et une phrase %s\nVoici un pointeur en hexa %p\n", a, a, a, a, d, c, s, s);
	return (a);
}