/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:45:38 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/13 19:27:36 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			ft_player_mv_hook(game, game->map->px, game->map->py - 1);
		if (keydata.key == MLX_KEY_S)
			ft_player_mv_hook(game, game->map->px, game->map->py + 1);
		if (keydata.key == MLX_KEY_A)
			ft_player_mv_hook(game, game->map->px - 1, game->map->py);
		if (keydata.key == MLX_KEY_D)
			ft_player_mv_hook(game, game->map->px + 1, game->map->py);
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
	}
}
