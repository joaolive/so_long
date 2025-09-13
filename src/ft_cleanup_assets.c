/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_assets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:05:16 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/12 13:53:41 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cleanup_assets(t_game *game)
{
	if (game->assets->wall)
		mlx_delete_image(game->mlx, game->assets->wall);
	if (game->assets->floor)
		mlx_delete_image(game->mlx, game->assets->floor);
	if (game->assets->player)
		mlx_delete_image(game->mlx, game->assets->player);
	if (game->assets->collect)
		mlx_delete_image(game->mlx, game->assets->collect);
	if (game->assets->exit)
		mlx_delete_image(game->mlx, game->assets->exit);
	free(game->assets);
}
