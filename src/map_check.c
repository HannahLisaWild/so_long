/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:14:42 by hawild            #+#    #+#             */
/*   Updated: 2024/07/23 16:30:40 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map_length(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_rectangular(t_data *data)
{
	int	rows;

	rows = 0;
	while (data->array[rows] != NULL)
		rows++;
	data->map_rows = rows;
	data->map_columns = get_map_length(data->array[0]);
	rows = 0;
	while (rows != data->map_rows)
	{
		if (get_map_length(data->array[rows]) != data->map_columns)
			return (-1);
		rows++;
	}
	return (0);
}

int	is_enclosed(t_data *data)
{
	int	i;

	i = 0;
	while (i != data->map_columns)
	{
		if (data->array[0][i] != '1' || data->array[data->map_rows
			- 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i != data->map_rows)
	{
		if (data->array[i][0] != '1' || data->array[i][data->map_columns
			- 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	is_valid(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (data->array[++i])
	{
		j = -1;
		while (data->array[i][++j])
		{
			if (data->array[i][j] != '1' && data->array[i][j] != '0'
				&& data->array[i][j] != 'P' && data->array[i][j] != 'E'
				&& data->array[i][j] != 'C')
				return (-1);
			if (data->array[i][j] == 'P')
				data->player += 1;
			if (data->array[i][j] == 'E')
				data->exit += 1;
			if (data->array[i][j] == 'C')
				data->collectables += 1;
		}
	}
	if (data->player != 1 || data->exit != 1 || data->collectables < 1)
		return (-1);
	return (0);
}