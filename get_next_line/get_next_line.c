/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:32:48 by seokang           #+#    #+#             */
/*   Updated: 2022/09/14 21:46:40 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_baguni_pugi(int fd, char **backup, int reres)
{
	char	*baguni;
	char	*temp;

	baguni = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!baguni)
		return (NULL);
	while (reres == BUFFER_SIZE)
	{
		if (ft_strchr(*backup, '\n'))
			break ;
		reres = read(fd, baguni, BUFFER_SIZE);
		if (reres == -1)
		{
			free(baguni);
			free(*backup);
			*backup = NULL;
			return (NULL);
		}
		if (reres == 0)
			break ;
		baguni[reres] = '\0';
		temp = ft_strjoin(*backup, baguni);
		free(*backup);
		*backup = temp;
	}
	free(baguni);
	return (*backup);
}

char	*ft_na_nugi(char	**result, char *backup, int *flag)
{
	int		idx;
	int		i;

	idx = 0;
	i = 0;
	while (backup[idx] && backup[idx] != '\n')
		idx++;
	if (backup[idx] == '\n')
		i++;
	*result = (char *)malloc(sizeof(char) * (idx + i + 1));
	if (!*result)
		return (NULL);
	i = -1;
	while (++i < idx)
		(*result)[i] = backup[i];
	if (backup[idx] == '\n')
		(*result)[i++] = '\n';
	(*result)[i] = '\0';
	if (ft_strchr(backup, '\n') && backup[++idx])
		backup = ft_strchr(backup, '\n') + 1;
	else
		*flag = 1;
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*backup;
	int			flag;

	flag = 0;
	if (fd < 0 || read(fd, 0, 0) < 0|| BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup)
	{
		backup = (char *)malloc(sizeof(char) * 1);
		if (!backup)
			return (NULL);
		backup[0] = '\0';
	}
	ft_baguni_pugi(fd, &backup, BUFFER_SIZE);
	if (!backup)
		return (NULL);
	if (!ft_strlen(backup))
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = ft_na_nugi(&result, backup, &flag);
	if (flag)
	{
		free(backup);
		backup = NULL;
	}
	return (result);
}
