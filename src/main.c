/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:44:05 by hawild            #+#    #+#             */
/*   Updated: 2024/07/22 19:57:40 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



int main(int ac, char **av)
{
    t_data data;

    if (ac == 2)
    {
        check_input(av[1], &data); // pass data: &data (allows to modify) else just data
    }
    else
        write(1, "Wrong argument count\n", 22);
    //data.mlx = mlx_init();
    return (0);
}