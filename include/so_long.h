/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:14:03 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/13 19:27:46 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../deps/libft/include/libft.h"
# include "../deps/mlx/include/MLX42/MLX42.h"

#define WALL_PATH "./assets/wall.png"
#define FLOOR_PATH "./assets/floor.png"
#define PLAYER_PATH "./assets/player.png"
#define COLLECTIBLE_PATH "./assets/collect.png"
#define EXIT_PATH "./assets/exit.png"

#define SPEED 5

typedef struct s_mstat
{
	int			height;
	int			width;
	int			px;
	int			py;
	int			player_count;
	int			collect_count;
	int			exit_count;
	int			exit_x;
	int			exit_y;
}	t_mstat;

typedef struct s_assets
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*collect;
	mlx_image_t	*exit;
}	t_assets;

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		px;
	int		py;
	int		collect_count;
	int		exit_count;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	mlx_t		*mlx;
	t_assets	*assets;
	int			collect_cap;
	bool		is_exit_open;
	int			move_count;
	double		time;
}	t_game;

t_map		*ft_initializr_map(char **grid, t_mstat *meta);
t_map		*ft_parse_map(char *path);
char		**ft_read_map(char *path);
int			ft_validate_suffix(char *file);
int			ft_validate_map(char **grid, t_mstat *meta);
int			ft_check_dimension(char **grid, t_mstat *meta);
int			ft_check_flags(char **grid, t_mstat *meta);
int			ft_check_roads(char **grid, t_mstat *meta);
int			ft_check_walls(char **grid, t_mstat *meta);
void		ft_flood_fill(char **grid, t_mstat *meta, int x, int y);
void		ft_clean_up(char **matrix);
char		**ft_fill_grid(int fd, size_t len);
size_t		ft_count_rows(int fd);

mlx_image_t	*ft_load_image(mlx_t *mlx, char *path);
bool		ft_load_all_images(t_game *game);
bool		ft_render(t_game *game);
void		ft_cleanup_assets(t_game *game);
void		ft_terminate(t_game *game);
t_game		*ft_initializr_game(t_map *map);
void		ft_hook_handler(mlx_key_data_t keydata, void *param);
void		ft_player_mv_hook(t_game *game, int new_x, int new_y);
void		ft_disable_collectible(t_game *game, int y, int x);
void		ft_print_error(char *str);
void		ft_close_window_hook(void *param);
#endif
