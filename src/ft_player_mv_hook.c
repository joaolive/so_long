/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_mv_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:43:21 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/13 15:28:52 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_mv_hook(t_game *game, int new_x, int new_y)
{
	if (game->map->grid[new_y][new_x] == '1')
		return ;
	game->map->px = new_x;
	game->map->py = new_y;
	game->assets->player->instances[0].x = new_x * 32;
	game->assets->player->instances[0].y = new_y * 32;
	if (game->map->grid[new_y][new_x] == 'C')
	{
		game->collect_cap++;
		game->map->grid[new_y][new_x] = '0';
		ft_disable_collectible(game, new_y, new_x);
		if (game->collect_cap == game->map->collect_count)
			game->is_exit_open = true;
	}
	if (game->map->grid[new_y][new_x] == 'E'
		&& game->is_exit_open)
		mlx_close_window(game->mlx);
	ft_printf("%d\n", game->move_count++);
	return ;
}
