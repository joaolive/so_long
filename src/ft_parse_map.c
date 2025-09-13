/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 08:04:33 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/12 18:58:46 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_initializr_meta(t_mstat *meta)
{
	meta->height = -1;
	meta->width = -1;
	meta->px = -1;
	meta->py = -1;
	meta->player_count = 0;
	meta->exit_x = -1;
	meta->exit_y = -1;
	meta->exit_count = 0;
	meta->collect_count = 0;
}

t_map	*ft_parse_map(char *path)
{
	t_mstat	meta;
	char	**grid;

	grid = ft_read_map(path);
	if (!grid)
		return (NULL);
	ft_initializr_meta(&meta);
	if (!ft_validate_map(grid, &meta))
		return (NULL);
	return (ft_initializr_map(grid, &meta));
}
