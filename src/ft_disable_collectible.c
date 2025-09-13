/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disable_collectible.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:35:15 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/13 14:09:18 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_disable_collectible(t_game *game, int y, int x)
{
	size_t	i;
	int		pixel_y;
	int		pixel_x;

	i = 0;
	pixel_y = y * 32;
	pixel_x = x * 32;
	while (i < game->assets->collect->count)
	{
		if (game->assets->collect->instances[i].y == pixel_y
			&& game->assets->collect->instances[i].x == pixel_x)
		{
			game->assets->collect->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}
