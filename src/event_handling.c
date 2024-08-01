/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:47:33 by hawild            #+#    #+#             */
/*   Updated: 2024/07/29 15:57:41 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	go_left(t_data *data)
{
	if (cases(data->player_y, data->player_x - 1, data) == -1)
		return (0);
	set_positions(data, 'l');
	make_move(data, 'l');
	print_moves(data);
	return (0);
}

int	go_right(t_data *data)
{
	if (cases(data->player_y, data->player_x + 1, data) == -1)
		return (0);
	set_positions(data, 'r');
	make_move(data, 'r');
	print_moves(data);
	return (0);
}

int	go_up(t_data *data)
{
	if (cases(data->player_y - 1, data->player_x, data) == -1)
		return (0);
	set_positions(data, 'u');
	make_move(data, 'u');
	print_moves(data);
	return (0);
}

int	go_down(t_data *data)
{
	if (cases(data->player_y + 1, data->player_x, data) == -1)
		return (0);
	set_positions(data, 'd');
	make_move(data, 'd');
	print_moves(data);
	return (0);
}

int	handle_keys(int key, t_data *data)
{
	if (key == 'a' || key == 65361)
		go_left(data);
	else if (key == 'w' || key == 65362)
		go_up(data);
	else if (key == 'd' || key == 65363)
		go_right(data);
	else if (key == 's' || key == 65364)
		go_down(data);
	else if (key == 113 || key == 65307)
		game_over(data);
	return (0);
}
