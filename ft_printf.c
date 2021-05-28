#include "lib.h"
#include <stdio.h>
#include <string.h>


static int ft_incorrect_argc_msg(size_t expected, size_t found)
{
    ft_putstr_fd("the number of arguments is not correct !!!  expected ",StdErr);
    ft_putnbr_fd(expected, StdErr);
    ft_putstr_fd(" but found ", StdErr);
    ft_putnbr_fd(found, StdErr);
    ft_putstr_fd("\n",StdErr);
    return (-1);
}

static int ft_incorrect_flags_msg()
{
    ft_putstr_fd("incorrect flag", StdErr);
    return (-1);
}

int     _ft_fprintf(int fd, const char *format, size_t argc, ...)
{
    int args_num;
    size_t out;
    va_list args;

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

int main()
{
    char *s = "hello world";
    int a,b,c,d;

    int aa = ft_printf("this is ft_printf:   d => |% d| i => |%i| c => |%c| s => |%s| p => |%p| n ==> |%n| x => |%x| X => |%X| o => |%o| u => |%u| n ==> |%n| |%%| this is an extension \n", *s, -120, *s, s, s, &a , -1325, 125, -15, -1, &c, 1, 1);
    int bb = printf("this is printf   :   d => |% d| i => |%i| c => |%c| s => |%s| p => |%p| n ==> |%n| x => |%x| X => |%X| o => |%o| u => |%u| n ==> |%n| |%%| this is an extension \n", *s, -120, *s, s, s, &b , -1325, 125, -15, -1, &d);
   // int c = printf("this is ft_printf:   d => |% d| i => |%i| c => |%c| s => |%s| p => |%p| x => |%x| X => |%X| o => |%o| u => |%u| |%%| this is an extension \n", *s, -120, *s, s, s , -1325, 125, -15, -1);


    printf("%d %d %d %d %d %d\n",a, b, c ,d, aa, bb);
}