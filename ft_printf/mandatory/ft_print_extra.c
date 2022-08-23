/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:57:14 by seokang           #+#    #+#             */
/*   Updated: 2022/08/22 20:16:25 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(unsigned char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	len;
	int	error;

	len = 0;
	error = 0;
	if (!(str))
		str = "(null)";
	while (*str)
	{
		error = write(1, str, 1);
		if (error == -1)
			return (-1);
		len += error;
		str++;
	}
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int					len;

	len = ft_print_hex((size_t)ptr, 'p');
	return (len);
}
