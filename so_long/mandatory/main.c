/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:36:33 by seokang           #+#    #+#             */
/*   Updated: 2023/03/11 15:14:45 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_err(char  *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    t_game  game;

    if (argc != 2)
        print_err("ERROR in arguments");
    ft_init_map(&game, argv[1]);
    return (0);
}