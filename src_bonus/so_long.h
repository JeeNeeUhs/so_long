/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:38:57 by ahekinci          #+#    #+#             */
/*   Updated: 2025/01/19 18:12:53 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>

typedef struct s_data
{
	int		x;
	int		y;
	int		window_width;
	int		window_height;
	int		square_size;
	char	**map;
	void	*mlx;
	void	*window;
	void	*sea;
	void	*tile;
	void	*berry;
	void	*character_right;
	void	*character_left;
	void	*character;
	void	**enemy;
	void	*exit;
	int		game_loop_counter;
	long	move_counter;
}	t_data;

typedef struct s_dfs
{
	char	**map;
	int		width;
	int		height;
	int		directions[4][2];
	int		x;
	int		y;
	int		goal_x;
	int		goal_y;
}	t_dfs;

// check_map.c
void	count_width_height(t_data *data, int fd);
void	filename_checker(char *str);
int		check_map(t_data *data, int start, int exit_c, int collectible);
void	checker(t_data *data, char **argv);

// check_paths.c
void	check_paths(t_data *data);
void	create_find(t_data *data, char **map, int x, int y);

// check_pos.c
int		check_collectible(t_data *data, char dir);
int		check_exit(t_data *data, char dir);
int		check_any_collectible(t_data *data);
int		check_enemy(t_data *data, int x, int y);
int		check_wall(t_data *data, char dir);

// draw.c
void	draw_image_to_cell(t_data *data, void *image, int x, int y);
void	draw_map(t_data *data);
void	draw_map_if(t_data *data, int x, int y);
void	draw_original_block(t_data *data, int x, int y);

// error.c
void	error_exit(t_data *data);
void	destroy_images(t_data *data);
void	free_map(t_data *data);
void	err(t_data *data);
int		expected_exit(void *param);

// find_in_map.c
void	find_player(t_data *data);
int		map_walls(char **map, int width, int height);

// import_data.c
void	import_images1(t_data *data);
void	import_images2(t_data *data);
void	init_map(t_data *data, char *file);
void	init_data(t_data *data);

// import_dfs.c
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**copy_map(char **original_map, int height, int width);
void	free_dfs(t_dfs *data);
void	set_directions(t_dfs *data_dfs);

// keys.c
void	key_w(t_data *data);
void	key_a(t_data *data);
void	key_s(t_data *data);
void	key_d(t_data *data);

// main.c
int		main(int argc, char **argv);
int		game_loop(void *param);
void	counter(t_data *data, int plus);
int		key_hook(int keycode, void *param);

// pathfinder.c
int		is_valid(t_dfs *data, int x, int y);
int		dfs(t_dfs *d);

// sprite.c
void	enemy_sprite(t_data *data, int x, int y);
void	enemy_sprite2(t_data *data, int x, int y);
void	move_enemy(t_data *data, char dir, int x, int y);

// utils.c
char	*ft_itoa(long n);

#endif