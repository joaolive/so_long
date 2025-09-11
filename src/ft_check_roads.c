/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_roads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:08:52 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/11 10:42:15 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_dup_meta(t_mstat *meta_cpy, t_mstat *meta)
{
	meta_cpy->height = meta->height;
	meta_cpy->width = meta->width;
	meta_cpy->player_x = meta->player_x;
	meta_cpy->player_y = meta->player_y;
	meta_cpy->player_count = 0;
	meta_cpy->exit_count = 0;
	meta_cpy->collectibles_count = 0;
}

static int	ft_validate_path_results(t_mstat *meta_cpy, t_mstat *meta)
{
	return ((meta_cpy->collectibles_count == meta->collectibles_count)
		&& (meta_cpy->exit_count == 1));
}

int	ft_check_roads(char **grid, t_mstat *meta)
{
	t_mstat	meta_copy;
	char	**grid_copy;

	ft_dup_meta(&meta_copy, meta);
	grid_copy = ft_strdup_matrix(grid);
	if (!grid_copy)
		return (0);
	ft_flood_fill(grid_copy, &meta_copy, meta->player_y, meta->player_x);
	ft_clean_up(grid_copy);
	return (ft_validate_path_results(&meta_copy, meta));
}
