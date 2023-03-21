/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:16:06 by seokang           #+#    #+#             */
/*   Updated: 2023/03/21 16:43:39 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

int		ft_strlen_g(char *s);
char	*ft_strjoin_g(char *s1, char *s2);
char	*ft_strchr_g(char *s, int c);
char	*ft_strndup_g(char *s, int start, int num);

#endif