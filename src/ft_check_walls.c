/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:39:33 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/09 18:23:12 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_walls(char **grid, t_mstat *meta)
{
	int	i;
	int	j;

	if (!grid || !*grid || !meta)
		return (0);
	j = 0;
	while (j < meta->width)
	{
		if (!(grid[0][j] == '1' && grid[meta->height -1][j] == '1'))
			return (0);
		j++;
	}
	i = 1;
	while (i < meta->height - 1)
	{
		if (!(grid[i][0] == '1' && grid[i][meta->width -1] == '1'))
			return (0);
		i++;
	}
	return (1);
}
