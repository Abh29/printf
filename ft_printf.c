#include "lib.h"
#include <stdio.h>
#include <string.h>

static int	ft_incorrect_argc_msg(size_t expected, size_t found)
{
	return (-1);
}

static int	ft_incorrect_flags_msg(void)
{
	return (-1);
}

char	*ft_format(char const *format, va_list args, int args_num, \
		size_t *fsize)
{
	char	*out;
	int		k;

	while (*format)
	{
		if (*format == '%')
			ft_format_flag(&format, args, &args_num, fsize);
		else
			ft_putchar_fd_size(*format, StdOut, fsize);
		format++;
	}
	return ("\n");
}

int	_ft_fprintf(int fd, const char *format, size_t argc, ...)
{
	int		args_num;
	size_t	out;
	va_list	args;

	out = 0;
	args_num = ft_args_expected_count(format);
	if (args_num == -1)
		return (ft_incorrect_flags_msg());
	if (args_num != argc)
		return (ft_incorrect_argc_msg(args_num, argc));
	va_start(args, argc);
	ft_format(format, args, args_num, &out);
	va_end(args);
	return ((int)out);
}

//TODO: DELETE THIS 
void	print_option(t_options ops)
{
	printf("sign : %d , precision : %ld , width : %ld ,\
	  filler : %c , l_shift : %d ,  prefix : %s", ops.sign, ops.precision, \
	   ops.width, ops.filler, ops.l_shift, ops.prefix);
}
