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
				ft_putstr_fd(va_arg(arglist, char), 1);
			if (input[i + 1] == 'p')
				ft_putstr_fd(va_arg(arglist, char), 1);
			if (input[i + 1] == 'd')
				ft_putnbr_fd(va_arg(arglist, char), 1);
			if (input[i + 1] == 'i')
				ft_putstr_fd(va_arg(arglist, char), 1);
			if (input[i + 1] == 'u')
				ft_putstr_fd(va_arg(arglist, char), 1);
			if (input[i + 1] == 'x')
				ft_putstr_fd(va_arg(arglist, char), 1);
			if (input[i + 1] == 'X')
				ft_putstr_fd(va_arg(arglist, char), 1);
			if (input[i + 1] == '%')
				ft_putstr_fd(va_arg(arglist, char), 1);
			else
				return (-1);
		}
		i++;
	}

	va_end(arglist);

}

/* #include <stdio.h>

int	main()
{
	int a = 42;
	printf("%s", a);
} */