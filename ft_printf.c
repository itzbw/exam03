#include <stdarg.h>
#include <unistd.h>

//short2.c

void ft_putstr_len (char *str, int *len)
{
    int i = 0;
    if(!str)
        str = "(null)";
    while (str[i])
        *len += write(1, &str[i++], 1);
}


void ft_put_digit_len (long long nbr, int base, int *len)
{
    char digit [] = "0123456789abcdef";
    
    if (nbr < 0)
    {
        nbr *= -1;
        *len += write(1, "-", 1);
    }
    if (nbr >= base)
        ft_put_digit_len ((nbr/base), base, len);
    *len += write(1, &digit[nbr % base], 1);

}

int ft_printf (const char *format, ...)
{
    int i = 0;
    int len = 0;
    va_list ptr;

    va_start(ptr,format); // (ap, param)
    while (format[i])
    {
        if(format[i] != '%')
            len += write (1, format, 1);
        else if ((format[i] == '%') && format[i + 1])
        {
            i++;
            if (format[i] == 's')
                ft_putstr_len(va_arg(ptr, char *), &len);
            else if (format[i] == 'x')
                ft_put_digit_len ((long long)va_arg(ptr, unsigned int), 16, &len);
            else if (format[i] == 'd')
                ft_put_digit_len ((long long)va_arg(ptr, int), 10, &len);

        }
        i++;
    }
    return (va_end(ptr), len);

}
