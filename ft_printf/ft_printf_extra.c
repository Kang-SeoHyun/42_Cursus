/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:57:14 by seokang           #+#    #+#             */
/*   Updated: 2022/08/16 19:20:38 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_print_ptr(void *ptr)
{
	int					len;

	len = ft_print_hex((size_t)ptr, 'x');
	return (len);
}
