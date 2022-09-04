/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:32:48 by seokang           #+#    #+#             */
/*   Updated: 2022/09/04 19:58:26 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*baguni_pugi(int fd, char *backup)
{
	// 첫호출이라면 1칸짜리 메모리 할당
	while (\n)
	{
		baguni_pugi
		backup = strjoin(backup + baguni)
	}
}

char	*return_mandulgi(char *backup)
{
	
}

char	*next_backup(char *backup)
{
	
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    //if (is_newline() == -1)
	backup = baguni_pugi(fd, backup);
	if (!backup)
		return (NULL);
	buf = return_mandulgi(backup);
	backup = next_backup(backup);
	return (buf);
}
