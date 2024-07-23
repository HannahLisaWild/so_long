/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:33:03 by hawild            #+#    #+#             */
/*   Updated: 2024/07/23 20:35:01 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

t_point	get_players_position(char **map, t_point size)
{
	t_point	player;
	int		i;
	int		j;

	player.x = -1;
	player.y = -1;
	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (map[i][j] == 'P')
			{
				player.x = j;
				player.y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (player);
}

char	**copy_map(char **map, t_point size)
{
	char	**copy;
	int		i;
	int		j;

	copy = malloc(sizeof(char *) * size.y);
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < size.y)
	{
		copy[i] = malloc(sizeof(char) * (size.x + 1));
		if (!copy[i])
		{
			ft_free(copy);
			return (NULL);
		}
		j = -1;
		while (++j < size.x)
			copy[i][j] = map[i][j];
		copy[i][j] = '\0';
	}
	copy[i] = NULL;
	return (copy);
}

int	is_path_valid(char **map, char **map_copy, t_point size,
		t_point player_position)
{
	int	valid;
	int	i;
	int	j;

	flood_fill(map_copy, size, player_position);
	valid = 0;
	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if ((map[i][j] == 'C' || map[i][j] == 'E') && map_copy[i][j] != 'F')
			{
				valid = -1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (valid);
}

int	path_check(t_data *data)
{
	t_point size;
	t_point player_position;
	char **map;
	char **map_copy;

	size.x = data->map_columns;
	size.y = data->map_rows;
	map = data->array;
	player_position = get_players_position(map, size);
	if (player_position.x == -1 || player_position.y == -1)
		return (-1);
	map_copy = copy_map(map, size);
	if (map_copy == NULL)
		return (-1);
	if (is_path_valid(map, map_copy, size, player_position) == -1)
	{
		ft_free(map_copy);
		return (-1);
	}
	ft_free(map_copy);
	return (0);
}