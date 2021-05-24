#include "lib.h"
#include <stdio.h>
#include <string.h>

int  ft_contians_char(char *s, char c)
{
    while (*s && *s != c)
        s++;
    return (*s == c);
}

void ft_put_var(char flag, va_list args, size_t size, char filler)
{
    if (flag == 'd' || flag == 'i') // for numbers TODO: handle options 
        ft_putnbr_fd((int)va_arg(args, int), StdOut);
    else if (flag == 's')  // for Strings 
        ft_putstr_fd((char *)va_arg(args, char *), StdOut);
    else if (flag == 'c')   //for characters
        ft_putchar_fd((int)va_arg(args, int), StdOut);
    else if (flag == 'p')
        ft_putptr_fd((void *)va_arg(args, void *), StdOut);
    else if (flag == 'x')
        ft_putnbr_base_fd((int)va_arg(args, int), Hex, StdOut);
    else if (flag == 'X')
        ft_putnbr_base_fd((int)va_arg(args, int), HEX, StdOut);
    else if (flag == 'o')
        ft_putnbr_base_fd((int)va_arg(args, int), Oct, StdOut);
    else if (flag == 'u')
        ft_putnbr_unsigned_fd((int)va_arg(args, int), StdOut);

}


void ft_format_flag(const char **format, va_list args, int *args_num)
{
    int hold;

    hold = 1;
    
    while (hold)
    {
        (*format)++;
        if (ft_contians_char(Supported_Options, **format))
        {
            //do something 
            printf("an option is detected ! %c\n",**format);
        }
        if (ft_contians_char(Supported_Flags, **format))
        {
            ft_put_var(**format, args, 0, 0);
            *args_num--;
            hold = 0;
        }
        else
        {
            ft_putchar_fd(**format, StdOut); 
        }
    }
}

char *ft_format(char const *format, va_list args, int args_num)
{
    char *out;
    int k;

    while (*format)
    {
        if (*format == '%')
            ft_format_flag(&format, args, &args_num);
        else
            ft_putchar_fd(*format, StdOut);
        format++;
    }
    return ("\n");
}

