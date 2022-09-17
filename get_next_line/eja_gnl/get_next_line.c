/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:47:52 by seokang           #+#    #+#             */
/*   Updated: 2022/09/17 21:53:00 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*buf_join(char *des, char *src, size_t slen, int *error)
{
	size_t	dlen;
	char	*join;

	if (!src || !src[0])
		return (des);
	dlen = 0;
	if (des)
		dlen = ft_strlen(des);
	if (slen > ft_strlen(src))
		slen = ft_strlen(src);
	join = ft_calloc(dlen + slen + 1, sizeof(char));
	if (!join)
	{
		*error = 1;
		free(des);
		return (NULL);
	}
	ft_memcpy(join, des, dlen);
	ft_memcpy(join + dlen, src, slen);
	free(des);
	ft_memmove(src, src + slen, BUFFER_SIZE - slen);
	ft_memset(src + BUFFER_SIZE - slen, 0, slen);
	return (join);
}

char	*get_next_line(int fd)
{
	static char	read_buf[BUFFER_SIZE];
	char		*res;
	ssize_t		idx;
	ssize_t		read_len;
	int			error;

	res = NULL;
	idx = -1;
	read_len = BUFFER_SIZE;
	error = 0;
	while (fd >= 0)
	{
		if (++idx == BUFFER_SIZE)
		{
			res = buf_join(res, read_buf, ft_strlen(read_buf), &error);
			read_len = read(fd, read_buf, BUFFER_SIZE);
			if (read_len < 0 || error)
				break ;
			idx = 0;
		}
		if (idx == read_len || read_buf[idx] == '\n')
			return (buf_join(res, read_buf, idx + 1, &error));
	}
	return (NULL);
}