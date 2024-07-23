/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:25:25 by hawild            #+#    #+#             */
/*   Updated: 2024/07/23 20:37:13 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 400
# endif

typedef struct s_data
{
	void	*mlx;
	char	**array;
	int		map_rows;
	int		map_columns;
	int		player;
	int		collectables;
	int		exit;

}			t_data;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int			check_input(char *input_file, t_data *data);
int			check_map(t_data *data);
int			get_map_length(char *s);
int			is_rectangular(t_data *data);
int			is_enclosed(t_data *data);
int			is_valid(t_data *data);
int			path_check(t_data *data);
void		ft_free(char **array);
t_point		get_players_position(char **map, t_point size);
char		**copy_map(char **map, t_point size);
int			is_path_valid(char **map, char **map_copy, t_point size,
				t_point player_position);

void		flood_fill(char **tab, t_point size, t_point begin);

char		**ft_split(char const *s, char c);

char		*get_next_line(int fd);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_strchr(char *s, char c);
char		*ft_strdup(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);

#endif