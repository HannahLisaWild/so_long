/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:43:52 by hawild            #+#    #+#             */
/*   Updated: 2024/07/23 16:36:11 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (-1);
}

int 	check_map(t_data *data)
{
	if (is_rectangular(data) == -1)
		return (error("Map is not rectangular (Error)\n"));
	if (is_enclosed(data) == -1)
		return (error("Map not enclosed (Error)\n"));
	data->player = 0;
	data->exit = 0;
	data->collectables = 0;
	if (is_valid(data) == -1)
		return (error("Map has invalid character (Error)\n"));
	if (path_check(data) == -1)
		return (error("Path is not valid (Error)\n"));
	return (0);
}

static int	read_and_store_map(char *file_data, t_data *data, int fd)
{
	char	*map_content;
	char	*temp;

	map_content = ft_strjoin("", file_data);
	while (file_data != NULL)
	{
		free(file_data);
		file_data = get_next_line(fd);
		if (file_data == NULL)
			break ;
		temp = ft_strjoin(map_content, file_data);
		free(map_content);
		map_content = ft_strdup(temp);
		free(temp);
	}
	data->array = ft_split(map_content, '\n');
	if (data->array == NULL)
	{
		free(map_content);
		return (error("Error while splitting\n"));
	}
	free(map_content);
	return (0);
}

int	check_input(char *input_file, t_data *data)
{
	int fd;
	char *file_data;

	if (access(input_file, F_OK | R_OK) != 0)
		return (error("Error accessing the file\n"));
	fd = open(input_file, O_RDONLY);
	if (fd == -1)
		return (error("Error opening the file\n"));
	file_data = get_next_line(fd);
	if (file_data == NULL)
		return (error("Empty file\n"));
	read_and_store_map(file_data, data, fd);
	if (close(fd) != 0)
		return (error("Error closing the file\n"));
	check_map(data);
	return (0);
}