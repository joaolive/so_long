/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:51:58 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/13 19:11:41 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static ssize_t	ft_image_printer(t_game *game, char value, int i, int j)
{
	int	y;
	int	x;

	x = j * 32;
	y = i * 32;
	if (value == '0')
		return (mlx_image_to_window(game->mlx, game->assets->floor, x, y));
	else if (value == '1')
		return (mlx_image_to_window(game->mlx, game->assets->wall, x, y));
	else if (value == 'P')
		return (mlx_image_to_window(game->mlx, game->assets->player, x, y));
	else if (value == 'E')
		return (mlx_image_to_window(game->mlx, game->assets->exit, x, y));
	else if (value == 'C')
		return (mlx_image_to_window(game->mlx, game->assets->collect, x, y));
	return (-1);
}

static bool	ft_render_assets(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (!(game->map->grid[i][j] == '0'))
				if (ft_image_printer(game, game->map->grid[i][j], i, j) < 0)
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	ft_render_base(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (ft_image_printer(game, '0', i, j) < 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_render(t_game *game)
{
	if (!ft_render_base(game) || !ft_render_assets(game))
	{
		ft_terminate(game);
		return (false);
	}
	return (true);
}
