/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:55:23 by seokang           #+#    #+#             */
/*   Updated: 2022/11/05 18:10:59 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_print_hex(size_t num, char format)
{
	int	len;

	len = 0;
	if (format == 'x' || format == 'X')
		num = (unsigned int)num;
	if ((num / 16) != 0)
	{
		len += ft_print_hex(num / 16, format);
		if (len == -1)
			return (-1);
		len += ft_print_hex(num % 16, format);
		if (len == -1)
			return (-1);
	}
	else
	{
		if (num < 10)
			len += ft_print_char(num + 48);
		else if (format == 'x' || format == 'p')
			len += ft_print_char(num + 87);
		else
			len += ft_print_char(num + 55);
	}
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
		if (len == -1)
			return (-1);
		num *= -1;
	}
	if (num / 10 != 0)
	{
		len += ft_print_num(num / 10);
		if (len == -1)
			return (-1);
		len += ft_print_num(num % 10);
	}
	else
		len += ft_print_char(num + 48);
	return (len);
}

int	ft_print_u_num(unsigned int num)
{
	int	len;
	int	check;

	len = 0;
	if (num / 10 != 0)
	{
		check = ft_print_u_num(num / 10);
		if (check == -1)
			return (-1);
		len += check;
		check = ft_print_u_num(num % 10);
		if (check == -1)
			return (-1);
		len += check;
	}
	else
		len += ft_print_char(num + 48);
	return (len);
}
