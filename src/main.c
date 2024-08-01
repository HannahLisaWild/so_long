/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:44:05 by hawild            #+#    #+#             */
/*   Updated: 2024/08/01 13:40:06 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	add_sprites(t_data *data)
{
	int	width;
	int	hight;

	data->win = mlx_new_window(data->mlx, (data->map_columns * 60),
			(data->map_rows * 60), "soooo long");
	data->wall = mlx_xpm_file_to_image(data->mlx, "./sprites/speaker60.xpm",
			&width, &hight);
	data->collect = mlx_xpm_file_to_image(data->mlx, "./sprites/coin.xpm",
			&width, &hight);
	data->p_left = mlx_xpm_file_to_image(data->mlx, "./sprites/left60.xpm",
			&width, &hight);
	data->p_right = mlx_xpm_file_to_image(data->mlx, "./sprites/right60.xpm",
			&width, &hight);
	data->backg = mlx_xpm_file_to_image(data->mlx, "./sprites/black60.xpm",
			&width, &hight);
	data->e_free = mlx_xpm_file_to_image(data->mlx, "./sprites/portal60.xpm",
			&width, &hight);
	data->e_n_free = mlx_xpm_file_to_image(data->mlx,
			"./sprites/earth60.xpm", &width, &hight);
}

int	create_window(char c, int x, int y, t_data *data)
{
	data->moves = 0;
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->p_right, y * 60, x
			* 60);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->e_n_free, y * 60, x
			* 60);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collect, y * 60, x
			* 60);
	else if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, y * 60, x
			* 60);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->backg, y * 60, x
			* 60);
	return (0);
}

static int	set_p_and_e(t_data *data)
{
	int	i;
	int	j;

	data->player_x = 0;
	data->player_y = 0;
	i = -1;
	while (data->array[++i])
	{
		j = -1;
		while (data->array[i][++j])
		{
			create_window(data->array[i][j], i, j, data);
			if (data->array[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			if (data->array[i][j] == 'E')
			{
				data->exit_x = j;
				data->exit_y = i;
			}
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		check;

	if (ac != 2)
		return (error("Wrong argument count (Error)\n"));
	check = check_input(av[1], &data);
	if (check == -1)
		return (ft_free(data.array));
	else if (check == 2)
		return (1);
	data.mlx = mlx_init();
	data.c_count = 0;
	data.old_pos_x = 0;
	data.old_pos_y = 0;
	data.last_move = 'r';
	data.playeronexit = 0;
	add_sprites(&data);
	set_p_and_e(&data);
	mlx_hook(data.win, 2, KeyPressMask, handle_keys, &data);
	mlx_hook(data.win, 17, 0, game_over, &data);
	mlx_loop(data.mlx);
	ft_free(data.array);
	return (0);
}
