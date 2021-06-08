#include "lib.h"

size_t     ft_args_expected_count(const char *format) //TODO: add more checks for the format (change this)
{
    size_t count;

    count = 0;
    while (*format)
        if (*format++ == '%')
            if (*format++ != '%')
                count++;
    return (count);
}
