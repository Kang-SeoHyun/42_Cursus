/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:36:33 by seokang           #+#    #+#             */
/*   Updated: 2023/03/10 20:58:53 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    t_game  game;

    if (argc != 2)
    {
        perror("ERROR in arguments");
        exit(1);
    }
    ft_init_map(&game, argv[1]);
    return (0);
}