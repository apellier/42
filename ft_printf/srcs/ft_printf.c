#include "../includes/includes.h"

int	ft_printf(const char *input, ...)
{
	va_list arglist;
	int		i;

	va_start(arglist, input);
	i = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			if (input[i + 1] == 'c')
				ft_putchar_fd(va_arg(arglist, char), 1);
			if (input[i + 1] == 's')
				ft_putstr_fd(va_arg(arglist, char *), 1);
			if (input[i + 1] == 'p')
				ft_putstr_fd(va_arg(arglist, char), 1); // the void * ponter argument has to be printed in hexadecimal format
			if (input[i + 1] == 'd')
				ft_putnbr_fd(va_arg(arglist, int), 1);
			if (input[i + 1] == 'i')
				ft_putstr_fd(va_arg(arglist, char), 1); // prints an integer in base 10
			if (input[i + 1] == 'u')
				ft_putstr_fd(va_arg(arglist, char), 1); // prints an unsigned decimal (base 10) number
			if (input[i + 1] == 'x')
				ft_putstr_fd(va_arg(arglist, char), 1); // prints a number in hexadecimal (base 16) lowercase format
			if (input[i + 1] == 'X')
				ft_putstr_fd(va_arg(arglist, char), 1); // prints a number in hexadecimal (base 16) lowercase format
			if (input[i + 1] == '%')
				ft_putchar_fd('%', 1);
			else
				return (-1);
		}
		i++;
	}
	va_end(arglist);
}

#include <stdio.h>

int	main()
{
	int a = 42;
	printf("%%");
}