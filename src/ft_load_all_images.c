/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_all_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:51:56 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/12 13:53:41 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_load_all_images(t_game *game)
{
	game->assets = ft_calloc(1, sizeof(t_assets));
	if (!game->assets)
		return (false);
	game->assets->wall = ft_load_image(game->mlx, WALL_PATH);
	game->assets->floor = ft_load_image(game->mlx, FLOOR_PATH);
	game->assets->player = ft_load_image(game->mlx, PLAYER_PATH);
	game->assets->collect = ft_load_image(game->mlx, COLLECTIBLE_PATH);
	game->assets->exit = ft_load_image(game->mlx, EXIT_PATH);
	if (!game->assets->wall || !game->assets->floor || !game->assets->player
		|| !game->assets->collect || !game->assets->exit)
	{
		ft_cleanup_assets(game);
		return (false);
	}
	return (true);
}
