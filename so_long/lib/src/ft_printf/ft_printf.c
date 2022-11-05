/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:30:20 by seokang           #+#    #+#             */
/*   Updated: 2022/11/05 18:11:02 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

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

int	ft_printf(const char *format, ...)
{
	int		len;
	int		error;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			error = ft_what_type(*(format + 1), &ap);
			len += error;
			format++;
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
