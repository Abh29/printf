#include "lib.h"


int  ft_contians_char(char *s, char c)
{
    while (*s && *s != c)
        s++;
    return (*s == c);
}

void ft_put_var_simple(char flag, va_list args, size_t *fsize)
{
    if (flag == 'd' || flag == 'i') // for numbers TODO: handle options 
        ft_putnbr_fd_size((int)va_arg(args, int), StdOut, fsize);
    else if (flag == 's')  // for Strings 
        ft_putstr_fd_size((char *)va_arg(args, char *), StdOut, fsize);
    else if (flag == 'c')   //for characters
        ft_putchar_fd_size((int)va_arg(args, int), StdOut, fsize);
    else if (flag == 'p')
        ft_putptr_fd_size((void *)va_arg(args, void *), StdOut, fsize);
    else if (flag == 'x')
        ft_putnbr_base_fd_size((int)va_arg(args, int), Hex, StdOut, fsize);
    else if (flag == 'X')
        ft_putnbr_base_fd_size((int)va_arg(args, int), HEX, StdOut, fsize);
    else if (flag == 'o')
        ft_putnbr_base_fd_size((int)va_arg(args, int), Oct, StdOut, fsize);
    else if (flag == 'u')
        ft_putnbr_unsigned_fd_size((int)va_arg(args, int), StdOut, fsize);
    else if (flag == '%')
        ft_putchar_fd_size('%', StdOut, fsize);
    else if (flag == 'n')
        *((int *)va_arg(args, int *)) = *fsize;
    else if (flag == 'f')
        ft_putdbl_fd_size((double)va_arg(args, double), StdOut, 6, fsize);
}


void ft_format_flag(const char **format, va_list args, int *args_num, size_t *fsize)
{
    int hold;

    hold = 1;
    
    while (hold)
    {
        (*format)++;
        if (ft_contians_char(Supported_Flags, **format))
        {
            ft_put_var_simple(**format, args, fsize);
            *args_num--;
            hold = 0;
        }
        else if (ft_contians_char(Supported_Options, **format))
        {
            //do something 
            printf("an option is detected ! %c\n",**format);
        }
        else
        {
            ft_putchar_fd_size(**format, StdOut, fsize); 
        }
    }
}

char *ft_format(char const *format, va_list args, int args_num, size_t  *fsize)
{
    char    *out;
    int     k;

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

