/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:25:25 by hawild            #+#    #+#             */
/*   Updated: 2024/08/01 13:31:25 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 400
# endif

# include <X11/X.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	char	**array;
	int		map_rows;
	int		map_columns;
	int		player;
	int		collectables;
	int		exit;
	void	*win;
	void	*collect;
	void	*wall;
	void	*backg;
	void	*e_free;
	void	*e_n_free;
	void	*p_left;
	void	*p_right;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		moves;
	int		c_count;
	int		old_pos_y;
	int		old_pos_x;
	char	last_move;
	int		playeronexit;

}			t_data;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

int			check_input(char *input_file, t_data *data);
int			check_map(t_data *data);
int			get_map_length(char *s);
int			is_rectangular(t_data *data);
int			is_enclosed(t_data *data);
int			is_valid(t_data *data);
int			path_check(t_data *data);
int			ft_free(char **array);
t_point		get_players_position(char **map, t_point size);
char		**copy_map(char **map, t_point size);
int			is_path_valid(char **map, char **map_copy, t_point size,
				t_point player_position);
int			error(char *str);
// event_handeling.c
int			go_right(t_data *data);
int			go_left(t_data *data);
int			go_down(t_data *data);
int			go_up(t_data *data);
int			handle_keys(int key, t_data *data);
// make_move.c
int			game_over(t_data *data);
int			cases(int next_pos_y, int next_pos_x, t_data *data);
void		put_back_exit(t_data *data, char c);
void		make_move(t_data *data, char c);
void		set_positions(t_data *data, char c);

void		print_moves(t_data *data);

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