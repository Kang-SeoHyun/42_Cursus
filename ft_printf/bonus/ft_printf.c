/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:30:20 by seokang           #+#    #+#             */
/*   Updated: 2022/08/23 19:49:52 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (len == -1)
			return (-1);
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

int	ft_what_flag(t_flag *flag, char format)
{
	if (format == '#')
		flag->hash = 1;
	else if (format == ' ' && flag->sign == 0)
		flag->space = 1;
	else if (format == '+')
		flag->sign = 1;
	else if (format == '-')
		flag->left = 1;
	else if (format == '0' && flag->left == 0)
		flag->zero = 1;
	else if (format == '.')
		flag->jeom = 1;
	else
		return (-1);
	return (0);
}

void	ft_flag_setting(t_flag *flag)
{
	flag->hash = 0;
	flag->space = 0;
	flag->sign = 0;
	flag->left = 0;
	flag->zero = 0;
	flag->jeom = 0;
}

int	ft_this_is_flag(const char *flag, char c)
{
	int	i;

	i = 0;
	while (flag[i])
	{
		if (flag[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		error;
	va_list	ap;
	t_flag	flag;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_flag_setting(&flag);
			while (*++format && ft_this_is_flag(FLAG, *format))
				ft_what_flag(&flag, *format);
			error = ft_what_type(*format, &ap);
			len += error;
		}
		else
		{
			error = ft_print_char(*format);
			len++;
		}
		if (error == -1)
			return (-1);
		format++;
	}
	va_end(ap);
	return (len);
}
