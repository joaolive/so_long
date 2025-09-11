/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:40:37 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/10 22:18:10 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_validate_flags(t_mstat *meta)
{
	if (!meta)
		return (0);
	return (!(meta->player_count != 1 || meta->collectibles_count <= 0
			|| meta->exit_count != 1 || meta->player_x < 0
			|| meta->player_y < 0));
}

static int	ft_mark_flags(char **grid, t_mstat *meta, size_t i, size_t j)
{
	if (grid[i][j] == 'P')
	{
		meta->player_count += 1;
		meta->player_y = i;
		meta->player_x = j;
	}
	else if (grid[i][j] == 'E')
	{
		meta->exit_count += 1;
		meta->exit_y = i;
		meta->exit_x = j;
	}
	else if (grid[i][j] == 'C')
		meta->collectibles_count += 1;
	else if (grid[i][j] != '0' && grid[i][j] != '1')
		return (0);
	return (1);
}

int	ft_check_flags(char **grid, t_mstat *meta)
{
	int	i;
	int	j;

	if (!grid || !*grid || !meta)
		return (0);
	i = 1;
	j = 1;
	while (grid[i] && i < meta->height - 1)
	{
		j = 1;
		while (grid[i][j] && j < meta->width - 1)
		{
			if (ft_mark_flags(grid, meta, i, j) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (ft_validate_flags(meta));
}
