#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_print_char(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (!(str))
		str = "(null)";
	while (*str)
	{
		len += write(1, str, 1);
		str++;
	}
	return (len);
}

int	ft_print_hex(size_t num, char format)
{
	int	len;

	len = 0;
	if (num / 16 != 0)
	{
		len += ft_print_hex(num / 16, format);
		len += ft_print_hex(num % 16, format);
	}
	else
	{
		if (num < 10)
			len += ft_print_char(num + 48);
		else if (format == 'x')
			len += ft_print_char(num + 87);
		else
			len += ft_print_char(num + 55);
	}
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int					len;

	len = ft_print_hex((size_t)ptr, 'x');
	return (len);
}

int	ft_print_num(int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
	{
		len += write(1, "-2147483648", 11);
		return (len);
	}
	if (num < 0)
	{
		len += write(1, "-", 1);
		num *= -1;
	}
	if (num / 10 != 0)
	{
		len += ft_print_num(num / 10);
		len += ft_print_num(num % 10);
	}
	else
		len += ft_print_char(num + 48);
	return (len);
}

int	ft_print_u_num(unsigned int num)
{
	int	len;

	len = 0;
	if (num / 10 != 0)
	{
		len += ft_print_u_num(num / 10);
		len += ft_print_u_num(num % 10);
	}
	else
		len += ft_print_char(num + 48);
	return (len);
	return (num);
}

int	ft_what_type(char format, va_list *ap)
{
	int		len;

	len = 0;
	if (format == 'c')
		len = ft_print_char(va_arg(*ap, int));
	else if (format == 's')
		len = ft_print_str(va_arg(*ap, char *));
	else if (format == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_print_ptr(va_arg(*ap, void *));
	}
	else if (format == 'd' || format == 'i')
		len = ft_print_num(va_arg(*ap, int));
	else if (format == 'u')
		len = ft_print_u_num(va_arg(*ap, int));
	else if (format == 'x' || format == 'X')
		len = ft_print_hex(va_arg(*ap, int), format);
	else if (format == '%')
		len += write(1, "%", 1);
	else
		return (0);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_what_type(*(format + 1), &ap);
			format++;
		}
		else
		{
			ft_print_char(*format);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}

int	main(void)
{
	int		result;

	result = printf("d: %d \n", 0xbd51d);
	printf("result: %d \n", result);
	result = printf("i: %i \n", 0xbd51d);
	printf("result: %d \n", result);
	printf("------------------my---------------\n");
	result = ft_printf("d: %d \n", 0xbd51d);
	printf("result: %d \n", result);
	result = ft_printf("i: %i \n", 0xbd51d);
	printf("result: %d \n", result);

/*
	result = printf("c: %d \n", 'a');
	printf("result: %d \n", result);
	result = printf("s: %s \n", "abc");
	printf("result: %d \n", result);
	result = printf("p: %p \n", &result);
	printf("result: %d \n", result);
	result = printf("d: %d \n", 7);
	printf("result: %d \n", result);
	result = printf("i: %i \n", -25);
	printf("result: %d \n", result);
	result = printf("u: %u \n", 25);
	printf("result: %d \n", result);
	*/
/*
	int i = 314;
	unsigned int j = -4294966982;
	result = printf("+d: %u \n", i);
	result = printf("-d: %u \n", j);
	printf("result: %d \n", result);
*/

/* pppppppppppppp
	result = printf("x: %x \n", 3144565464564544568);
	printf("result: %d \n", result);
	result = printf("X: %X \n", 3144565464564544568);
	printf("result: %d \n", result);
	result = ft_printf("x: %x \n", 3144565464564544568);
	printf("result: %d \n", result);
	result = ft_printf("X: %X \n", 3144565464564544568);
	printf("result: %d \n", result);
*/
	/*
	result = printf("percent: %% \n");
	printf("result: %d \n", result);
	printf("-------------------------\n");
	printf("-------------------------\n");

	result = ft_printf("my c: %c \n", 'a');
	printf("result: %d \n", result);
	result = printf("my c: %c \n", 'a');
	printf("result: %d \n", result);
	printf("-------------------------\n");

	result = ft_printf("my s: %s \n", "\0");
	printf("result: %d \n", result);
	result = printf("my s: %s \n", "\0");
	printf("result: %d \n", result);
	printf("-------------------------\n2\n");
	result = ft_printf("my s: %s \n", "");
	printf("result: %d \n", result);
	result = printf("my s: %s \n", "");
	printf("result: %d \n", result);
	printf("-------------------------\n3\n");

	result = ft_printf("my s: %s \n", NULL);
	printf("result: %d \n", result);
	result = printf("my s: %s \n", NULL);
	printf("result: %d \n", result);
	printf("-------------------------\n");

	result = ft_printf("my %%: %% \n");
	printf("result: %d \n", result);
	result = printf("my %%: %% \n");
	printf("result: %d \n", result);
	printf("-------------------------\n");
*/
/*
	result = ft_printf("my c: %c \n", '\0');
	printf("result: %d \n", result);
	result = printf("my c: %c \n", '\0');
	printf("result: %d \n", result);
	printf("-------------------------\n2\n");
	result = ft_printf("my c: %c \n");
	printf("result: %d \n", result);
	result = printf("my c: %c \n");
	printf("result: %d \n", result);
*/
/*
int a;

a=1;
	result = ft_printf("my p: %p \n", &a);
	printf("result: %d \n", result);
	result = printf("my p: %p \n", &a);
	printf("result: %d \n", result);
	printf("-------------------------\n2\n");
*/
	/*
	result = ft_printf("my c: %x \n", -310004);
	printf("result: %d \n", result);
	result = printf("my c: %x \n", -310004);
	printf("result: %d \n", result);
	printf("-------------------------\n2\n");
	result = ft_printf("my c: %X \n", -310004);
	printf("result: %d \n", result);
	result = printf("my c: %X \n", -310004);
	printf("result: %d \n", result);
	*/

}
