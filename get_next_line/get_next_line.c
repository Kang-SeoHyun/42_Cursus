/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:32:48 by seokang           #+#    #+#             */
/*   Updated: 2022/09/06 23:03:12 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_baguni_pugi(int fd, char *backup, int reres)
{
	char	*buf;
	//char	*new_backup;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (reres == BUFFER_SIZE)
	{
		reres = read(fd, buf, BUFFER_SIZE);
		if (reres == -1)
		{
			free(buf);
			free(backup);
			return (NULL);
		}
		buf[reres] = '\0';
		backup = ft_strjoin(backup, buf);
printf("\n1: before free b: %s\n", backup);
//printf("\n2: before free new_b: %s\n", new_backup);
	//	free(backup);
	//	backup = new_backup;
printf("\n3: after free b: %s\n", backup);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (backup);
}

char	*ft_na_nugi(char	**buf, char *backup)
{
	int	idx;
	int	i;
	char	*temp;

	idx = 0;
	i = 0;
	while (backup[idx] && backup[idx] != '\n')
		idx++;
	if (backup[idx] == '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * (idx + i + 1));
	if (!temp)
		return (NULL);
	i = -1;
	while (++i < idx)
		temp[i] = backup[i];
	if (backup[idx] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	*buf = temp;
	backup = ft_strchr(backup, '\n') + 1;
printf("in nanugi b: %s\n", backup);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup == 0)	// ㅊㅓㅅ호출
	{
		backup = (char *)malloc(sizeof(char) * 1);
		*backup = '\0';
	}
	backup = ft_baguni_pugi(fd, backup, BUFFER_SIZE);
	if (!backup)
		return (NULL);
	backup = ft_na_nugi(&buf, backup);
	return (buf);
}

int	main(void)
{
	int		fd;
	int		i;

	i = 0;
	if ((fd = open("a.txt", O_RDONLY)))
	{
		while (i++ < 3)
		{
			printf("\nresult: %s", get_next_line(fd));
		}
	}
	return (0);
}
