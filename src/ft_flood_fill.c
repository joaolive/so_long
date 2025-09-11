/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:28:18 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/11 09:22:47 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **grid, t_mstat *meta, int y, int x)
{
	if (!grid || !*grid || !meta)
		return ;
	if (x >= meta->width || x < 0 || y >= meta->height || y < 0)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'F' || grid[y][x] == 'X')
		return ;
	if (grid[y][x] == 'C')
		meta->collectibles_count++;
	if (grid[y][x] == 'E')
	{
		grid[y][x] = 'X';
		meta->exit_count++;
		return ;
	}
	grid[y][x] = 'F';
	ft_flood_fill(grid, meta, y + 1, x);
	ft_flood_fill(grid, meta, y - 1, x);
	ft_flood_fill(grid, meta, y, x + 1);
	ft_flood_fill(grid, meta, y, x - 1);
	return ;
}
