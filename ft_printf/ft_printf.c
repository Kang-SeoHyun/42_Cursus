#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void ft_print_char(char c)
{
	write(1,&c,1);
}
void ft_print_str();
void ft_print_ptr();
void ft_print_num(int c)
{
	write(1, &c ,1);
}
void ft_print_hex();

int	ft_what_type(char *format, int c)
{
		if (format == 'c')
			ft_print_char(c);
		else if (format == 's')
			ft_print_str();
		else if (format == 'p')
			ft_print_ptr();
		else if (format == 'd' || format == 'i' || format == 'u')
			ft_print_num(c);
		else if (format == 'x' || format == 'X')
			ft_print_hex();
		else if (format == '%')
			write(1,'%',1);
		else
			return (-1);
}

int ft_printf(const char *format, ...)
{
	int		conversion;
	int		result;
	va_list	ap;

	conversion = 0;
	result = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			int c = va_arg(ap, int);
			conversion = ft_what_type(*(format + 1), c);
			if (conversion == -1);
			else
			{
				*format++;
				result++;
			}
		}
		else
		{
			ft_print_char(*format);
			result++;
		}
		*format++;
	}
	va_end(ap);
	return (result);
}

void main()
{
	char	c = 'a';
	char	s[3] = "ab";
	void*	p;
	int		d = 7;
	int		i = -25;
	int		u = 25;
	int		x = 314;
	int		X = 314;
	int		result;
/*
	result = printf("c: %c \n", c);
	printf("result: %d \n", result);
	
	result = printf("s: %s \n", s);
	printf("result: %d \n", result);
	
	result = printf("p: %p \n", p);
	printf("result: %d \n", result);
	
	result = printf("d: %d \n", d);
	printf("result: %d \n", result);
	
	result = printf("i: %i \n", i);
	printf("result: %d \n", result);
	
	result = printf("u: %u \n", u);
	printf("result: %d \n", result);
	
	result = printf("x: %x \n", x);
	printf("result: %d \n", result);
	
	result = printf("X: %X \n", X);
	printf("result: %d \n", result);
	
	result = printf("percent: %% \n");
	printf("result: %d \n", result);
	
	printf("-------------------------\n");
*/
	result = ft_printf("my c: %c \n", c);
	printf("result: %d \n", result);
	result = printf("my c: %c \n", c);
	printf("result: %d \n", result);

	result = ft_printf("my d: %d \n", d);
	printf("result: %d \n", result);
	result = printf("my d: %d \n", d);
	printf("result: %d \n", result);
}