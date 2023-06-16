/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:36 by gsong             #+#    #+#             */
/*   Updated: 2023/06/10 16:33:36 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_type_of_component(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (NO);
	else if (!ft_strncmp(line, "SO ", 3))
		return (SO);
	else if (!ft_strncmp(line,"WE ", 3))
		return (WE);
	else if (!ft_strncmp(line, "EA ", 3))
		return (EA);
	else
		return (FALSE);
}

int	get_type_of_color(char *line)
{
	if (!ft_strncmp(line, "F ", 2))
		return (F);
	else if (!ft_strncmp(line, "C ", 2))
		return (C);
	else
		return (FALSE);
}

int	get_type_of_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!is_contain(MAP_COMPONENT, line[i]))
			return (FALSE);
	}
	return (MAP);
}

int	get_type(char *line)
{
	int	type;

	type = get_type_of_component(line);
	if (type)
		return (type);
	type = get_type_of_color(line);
	if (type)
		return (type);
	type = get_type_of_map(line);
	return (type);
}
