/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:59:20 by hawild            #+#    #+#             */
/*   Updated: 2024/07/29 17:29:39 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game_over(t_data *data)
{
	int	i;

	i = -1;
	while (data->array[++i] != NULL)
		free(data->array[i]);
	free(data->array);
	mlx_destroy_image(data->mlx, data->backg);
	mlx_destroy_image(data->mlx, data->p_right);
	mlx_destroy_image(data->mlx, data->p_left);
	mlx_destroy_image(data->mlx, data->collect);
	mlx_destroy_image(data->mlx, data->e_free);
	mlx_destroy_image(data->mlx, data->e_n_free);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	write(1, "GAME OVER!\n", 12);
	exit(0);
	return (0);
}

int	cases(int next_pos_y, int next_pos_x, t_data *data)
{
	if (data->array[next_pos_y][next_pos_x] == '1')
		return (-1);
	else if (data->array[next_pos_y][next_pos_x] == 'E')
	{
		if (data->c_count != data->collectables)
			data->playeronexit = 1;
		else if (data->c_count == data->collectables)
			game_over(data);
		return (0);
	}
	else if (data->array[next_pos_y][next_pos_x] == '0')
		return (0);
	else if (data->array[next_pos_y][next_pos_x] == 'C')
	{
		data->c_count += 1;
		if (data->c_count == data->collectables)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->e_free,
				data->exit_x * 60, data->exit_y * 60);
			return (0);
		}
	}
	return (0);
}

void	put_back_exit(t_data *data, char c)
{
	if (c == 'l' || (c == 'u' && data->last_move == 'l') || (c == 'd'
			&& data->last_move == 'l'))
	{
		mlx_put_image_to_window(data->mlx, data->win, data->p_left,
			data->player_x * 60, data->player_y * 60);
		mlx_put_image_to_window(data->mlx, data->win, data->e_n_free,
			data->old_pos_x * 60, data->old_pos_y * 60);
		data->array[data->old_pos_y][data->old_pos_x] = 'E';
		data->array[data->player_y][data->player_x] = 'P';
	}
	else if (c == 'r' || (c == 'u' && data->last_move == 'r') || (c == 'd'
			&& data->last_move == 'r'))
	{
		mlx_put_image_to_window(data->mlx, data->win, data->p_right,
			data->player_x * 60, data->player_y * 60);
		mlx_put_image_to_window(data->mlx, data->win, data->e_n_free,
			data->old_pos_x * 60, data->old_pos_y * 60);
		data->array[data->old_pos_y][data->old_pos_x] = 'E';
		data->array[data->player_y][data->player_x] = 'P';
	}
	data->playeronexit = 0;
}

void	make_move(t_data *data, char c)
{
	if (data->playeronexit == 2)
		put_back_exit(data, c);
	else if (c == 'l' || (c == 'u' && data->last_move == 'l') || (c == 'd'
			&& data->last_move == 'l'))
	{
		mlx_put_image_to_window(data->mlx, data->win, data->p_left,
			data->player_x * 60, data->player_y * 60);
		mlx_put_image_to_window(data->mlx, data->win, data->backg,
			data->old_pos_x * 60, data->old_pos_y * 60);
		data->array[data->old_pos_y][data->old_pos_x] = '0';
		data->array[data->player_y][data->player_x] = 'P';
	}
	else if (c == 'r' || (c == 'u' && data->last_move == 'r') || (c == 'd'
			&& data->last_move == 'r'))
	{
		mlx_put_image_to_window(data->mlx, data->win, data->p_right,
			data->player_x * 60, data->player_y * 60);
		mlx_put_image_to_window(data->mlx, data->win, data->backg,
			data->old_pos_x * 60, data->old_pos_y * 60);
		data->array[data->old_pos_y][data->old_pos_x] = '0';
		data->array[data->player_y][data->player_x] = 'P';
	}
	if (data->playeronexit == 1)
		data->playeronexit = 2;
}

void	set_positions(t_data *data, char c)
{
	data->old_pos_x = data->player_x;
	data->old_pos_y = data->player_y;
	if (c == 'l')
	{
		data->player_x = data->old_pos_x - 1;
		data->player_y = data->old_pos_y;
	}
	else if (c == 'r')
	{
		data->player_x = data->old_pos_x + 1;
		data->player_y = data->old_pos_y;
	}
	else if (c == 'u')
	{
		data->player_x = data->old_pos_x;
		data->player_y = data->old_pos_y - 1;
	}
	else if (c == 'd')
	{
		data->player_x = data->old_pos_x;
		data->player_y = data->old_pos_y + 1;
	}
}
