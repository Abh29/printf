#include "lib.h"

size_t	ft_args_expected_count(const char *format)
{
	size_t	count;

	count = 0;
	while (*format)
	{
		if (*format++ == '%')
		{
			while (*format && ft_strchr(Supported_Options, (int)*format))
			{
				if (*format == '*')
					count++;
				format++;
			}
			if (*format != '%')
			{
				if (*format && ft_strchr(Supported_Flags, (int)*format))
					count++;
				else
					return (-1);
			}
			format++;
		}
	}
	return (count);
}

char	ft_get_flag(const char *s)
{
	while (ft_strchr(Supported_Flags, *s) == NULL)
		s++;
	return (*s);
}

static void	ft_fistcheck(const char **format, va_list args, char *flag, \
			t_options *out)
{
	*out = NULLOPTION;
	if (**format == '#')
	{
		if (*flag == 'x')
			out->prefix = "0x";
		else if (*flag == 'X')
			out->prefix = "0X";
		else if (*flag == 'o')
			out->prefix = "0";
		else if (ft_strchr("efg", *flag))
			out->prefix = "0";
	}
	else if (**format == '+')
		out->sign = 1;
	else if (**format == '-')
		out->l_shift = 1;
	else if (**format == ' ')
		out->filler = ' ';
	else if (**format == '0')
		out->filler = '0';
}

static void	ft_secondcheck(const char **format, va_list args, char *flag, \
		t_options *out)
{
	int	n;

	if (**format == '*')
	{
		n = (int)va_arg(args, int);
		if (n < 0)
		{
			n *= -1;
			out->l_shift = 1;
		}
		out->width = (size_t)n;
	}
	else if (ft_isdigit(**format))
	{
		n = ft_atoi(*format);
		out->width = (size_t)n;
		while (ft_isdigit(**format))
			(*format)++;
		(*format)--;
	}
}

t_options	ft_extract_options(const char **format, va_list args, char *flag)
{
	t_options	out;
	int			n;

	*flag = ft_get_flag(*format);
	while (**format && **format != *flag)
	{
		ft_fistcheck(format, args, flag, &out);
		ft_secondcheck(format, args, flag, &out);
		if (**format == '.')
		{
			(*format)++;
			if (**format == '*')
				n = (int)va_arg(args, int);
			else
			{
				n = ft_atoi(*format);
				while (ft_isdigit(**format))
					(*format)++;
				(*format)--;
			}
			out.precision = (size_t)n;
		}
		(*format)++;
	}
	return (out);
}
