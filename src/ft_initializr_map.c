/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializr_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:48:52 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/09 14:24:13 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*ft_initializr_map(char **grid, t_mstat *meta)
{
	t_map		*map;

	if (!grid || !*grid)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = grid;
	map->height = meta->height;
	map->width = meta->width;
	map->collectibles_count = meta->collectibles_count;
	map->exit_count = meta->exit_count;
	map->player_pos.x = meta->player_x;
	map->player_pos.y = meta->player_y;
	return (map);
}
