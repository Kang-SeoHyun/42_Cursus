/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:19:52 by seokang           #+#    #+#             */
/*   Updated: 2022/08/23 22:11:21 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# define TYPE "csdiuXxp%"
# define FLAG "# +-0.123456789"

typedef struct s_flag
{
	int		hash;
	int		space;
	int		sign;
	int		left;
	int		zero;
	int		jeom;
	char	width[20];
}				t_flag;

int		ft_printf(const char *format, ...);
int		ft_what_type(char format, va_list *ap);
int		ft_print_char(unsigned char c);
int		ft_print_str(char *str);
int		ft_print_ptr(void *ptr);
int		ft_print_hex(size_t num, char format);
int		ft_print_num(int num);
int		ft_print_u_num(unsigned int num);

#endif