#include "lib.h"

void	ft_put_var_simple_bonus(char flag, va_list args, size_t *fsize)
{
	if (flag == 'n')
		*((int *)va_arg(args, int *)) = *fsize;
	else if (flag == 'f')
		ft_putdbl_fd_size((long double)va_arg(args, double), StdOut, \
		fsize, SIMPLE_DBL);
	else if (flag == 'e')
		ft_putdbl_exp_fd_size((double)va_arg(args, double), StdOut, \
		fsize, SIMPLE_DBL);
}

void	ft_put_var_simple(char flag, va_list args, size_t *fsize)
{
	if (flag == 'd' || flag == 'i')
		ft_putnbr_fd_size((int)va_arg(args, int), StdOut, fsize, SIMPLE_DEC);
	else if (flag == 's')
		ft_putstr_fd_size((char *)va_arg(args, char *), StdOut, fsize, S_D);
	else if (flag == 'c')
		ft_putchar_fd_size((int)va_arg(args, int), StdOut, fsize);
	else if (flag == 'p')
		ft_putptr_fd_size((void *)va_arg(args, void *), StdOut, fsize, S_D);
	else if (flag == 'x')
		ft_putnbr_base_fd_size((int)va_arg(args, int), Hex, StdOut, fsize, S_D);
	else if (flag == 'X')
		ft_putnbr_base_fd_size((int)va_arg(args, int), HEX, StdOut, fsize, S_D);
	else if (flag == 'o')
		ft_putnbr_base_fd_size((int)va_arg(args, int), Oct, StdOut, fsize, S_D);
	else if (flag == 'u')
		ft_putnbr_unsigned_fd_size((int)va_arg(args, int), StdOut, fsize, S_D);
	else if (flag == '%')
		ft_putchar_fd_size('%', StdOut, fsize);
	else
		ft_put_var_simple_bonus(flag, args, fsize);
}

void	ft_put_var_options_bonus(char flag, va_list args, size_t *fsize, \
		 t_options options)
{
	if (flag == 'n')
		*((int *)va_arg(args, int *)) = *fsize;
	else if (flag == 'f')
		ft_putdbl_fd_size((long double)va_arg(args, double), \
		StdOut, fsize, options);
	else if (flag == 'e')
		ft_putdbl_exp_fd_size((double)va_arg(args, double), \
		StdOut, fsize, options);
}

void	ft_put_var_options(char flag, va_list args, size_t *fsize, t_options op)
{
	if (flag == 'd' || flag == 'i')
		ft_putnbr_fd_size((int)va_arg(args, int), StdOut, fsize, op);
	else if (flag == 's')
		ft_putstr_fd_size((char *)va_arg(args, char *), StdOut, fsize, op);
	else if (flag == 'c')
		ft_putchar_fd_size_options((int)va_arg(args, int), StdOut, fsize, op);
	else if (flag == 'p')
		ft_putptr_fd_size((void *)va_arg(args, void *), StdOut, fsize, op);
	else if (flag == 'x')
		ft_putnbr_base_fd_size((int)va_arg(args, int), Hex, StdOut, fsize, op);
	else if (flag == 'X')
		ft_putnbr_base_fd_size((int)va_arg(args, int), HEX, StdOut, fsize, op);
	else if (flag == 'o')
		ft_putnbr_base_fd_size((int)va_arg(args, int), Oct, StdOut, fsize, op);
	else if (flag == 'u')
		ft_putnbr_unsigned_fd_size((int)va_arg(args, int), StdOut, fsize, op);
	else if (flag == '%')
		ft_putchar_fd_size('%', StdOut, fsize);
	else
		ft_put_var_options_bonus(flag, args, fsize, op);
}

void	ft_format_flag(const char **format, va_list args, \
		int *args_num, size_t *fsize)
{
	int			hold;
	char		flag;
	t_options	options;

	hold = 1;
	while (hold)
	{
		(*format)++;
		if (ft_strchr(Supported_Flags, **format))
		{
			hold = 0;
			ft_put_var_simple(**format, args, fsize);
			(*args_num)--;
		}
		else if (ft_strchr(Supported_Options, **format))
		{
			options = ft_extract_options(format, args, &flag);
			ft_put_var_options(flag, args, fsize, options);
			hold = 0;
		}
	}
}
