/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:32:44 by seokang           #+#    #+#             */
/*   Updated: 2023/03/10 21:20:29 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_check_file_type(char *file_name)
{
    if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".ber", 4))
}

void    ft_init_map(t_game *game, char *file_name)
{
    ft_check_file_type(file_name);
}