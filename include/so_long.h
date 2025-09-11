/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:14:03 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/11 10:32:49 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../deps/libft/include/libft.h"
# include "../deps/mlx/mlx.h"


typedef struct s_mstat
{
	int			height;
	int			width;
	int			player_x;
	int			player_y;
	int			player_count;
	int			collectibles_count;
	int			exit_count;
	int			exit_x;
	int			exit_y;
}	t_mstat;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char		**grid;
	int			height;
	int			width;
	t_player	player_pos;
	int			collectibles_count;
	int			exit_count;
}	t_map;

typedef struct s_game
{
	t_map	*map;
}	t_game;

t_map	*ft_initializr_map(char **grid, t_mstat *meta);
t_map	*ft_parse_map(char *path);
char	**ft_read_map(char *path);
char	**ft_fill_grid(int fd, size_t len);
size_t	ft_count_rows(int fd);
int		ft_validate_suffix(char *file);
int		ft_validate_map(char **grid, t_mstat *meta);
int		ft_check_dimension(char **grid, t_mstat *meta);
int		ft_check_flags(char **grid, t_mstat *meta);
int		ft_check_roads(char **grid, t_mstat *meta);
int		ft_check_walls(char **grid, t_mstat *meta);
void	ft_flood_fill(char **grid, t_mstat *meta, int x, int y);
void	ft_clean_up(char **matrix);
#endif
