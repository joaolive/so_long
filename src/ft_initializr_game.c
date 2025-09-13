/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializr_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:16:16 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/13 14:06:51 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*ft_initializr_game(t_map *map)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = map;
	game->mlx = NULL;
	game->assets = NULL;
	game->move_count = 0;
	game->time = 0;
	game->collect_cap = 0;
	return (game);
}
